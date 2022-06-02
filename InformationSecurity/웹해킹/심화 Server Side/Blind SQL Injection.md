## Blind SQL Injection
### Binary Search
---
이미 정렬된 리스트에서 임의의 값을 효율적으로 찾기 위한 알고리즘이다. 
#### 과정
* 1. 범위 지정
0부터 100사이의 범위 내에 한 숫자만이 정답일 때 범위의 중간 값으로 설정한다.
* 2. 범위 조절
설정한 값보다 큰값인지 확인한다. 큰 값이거나 아니라면 다시 검색 범위를 좁혀나간다. 그렇게 해서 최종적으로 정답을 찾아낼 수 있다.
#### 사용 예시
`substr`함수의 반환값을 비교하여 패스워드를 알아낼 수 있다. 비밀번호에서 쓰이는 아스키 문자 범위는 32부터 126이므로 중간값 79로 비교한다.
```sql
select * from users where username='admin' and ascii(substr(password, 1, 1))>79;
```
### Bit 연산
ASCII는 0부터 127까지의 문자를 표현하며, 곧 7개의 비트를 통해 하나의 문자로 나타낼 수 있음을 의미한다. 따라서 7개의 비트에 대해 1인지 비교하면 총 7번의 쿼리로 한 바이트를 알아낼 수 있다. MySQL에서는 `bin`이라는 함수를 제공해준다. 
```sql
select * from users where username='admin' and substr(bin(ord(password)), 1, 1)=1
``` 