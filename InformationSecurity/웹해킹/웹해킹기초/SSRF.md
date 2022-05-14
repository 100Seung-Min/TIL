## SSRF
### SSRF (Server Side Request Forgery)
---
웹 서비스는 외부에서 접근할 수 없는 내부망의 기능을 사용할 때가 있다. 내부망의 기능은 백오피스를 예로 들 수 있다. 백오피스는 관리자 페이지라고도 불리며, 이용자의 행위가 의심스러울 때 해당 계정을 정지시키거나 삭제하는 등 관리자만이 수행할 수 있는 모든 기능을 수현한 서비스이다. 웹 서비스는 의심스러운 행위를 탐지하고, 실시간으로 대응하기 위해 백오피스의 기능을 실행할 수 있다. 다시 말해, 내부망 서비스와 통신할 수 있다. 만약 공격자가 웹 서비스의 권한으로 요청을 보낼 수 있다면, 외부에서 간접적으로 내부망을 이용할 수 있다. 하지만 요청을 변조하기 위해서는 요청 내에 이용자의 입력값이 포함되어 있어야 한다.
### 이용자가 입력한 URL에 요청
---
```py
from flask import Flask, request
import requests
app = Flask(__name__)
@app.route("/image_downloader")
def image_downloader():
    # 이용자가 입력한 URL에 HTTP 요청을 보내고 응답을 반환하는 페이지 입니다.
    image_url = request.args.get("image_url", "") # URL 파라미터에서 image_url 값을 가져옵니다.
    response = requests.get(image_url) # requests 라이브러리를 사용해서 image_url URL에 HTTP GET 메소드 요청을 보내고 결과를 response에 저장합니다.
    return ( # 아래의 3가지 정보를 반환합니다.
        response.content, # HTTP 응답으로 온 데이터
        200, # HTTP 응답 코드
        {"Content-Type": response.headers.get("Content-Type", "")}, # HTTP 응답으로 온 헤더 중 Content-Type(응답 내용의 타입)
    )
@app.route("/request_info")
def request_info():
    # 접속한 브라우저(User-Agent)의 정보를 출력하는 페이지 입니다.
    return request.user_agent.string
app.run(host="127.0.0.1", port=8000)
```
#### `/image_downloader` 엔드 포인트
이용자가 입력한 `image_url`을 `request.get` 함수를 사용해 GET 메소드로 HTTP 요청을 보내고 응답을 반환한다.
#### `/request_info` 엔드 포인트
웹 페이지에 접속한 브라우저의 정보를 반환한다. 
#### 문제점
`image_downloader`에서 `request_info`로 요청을 보내면, 브라우저 정보가 `python-requests`로  출력된다. 그렇게 되면 직접 접근 할 수 없는 마이크로서비스의 기능을 임의로 사용할 수 있다.
### 웹 서비스의 요청 URL에 이용자의 입력값이 포함
---
```py
INTERNAL_API = "http://api.internal/"
# INTERNAL_API = "http://172.17.0.3/"
@app.route("/v1/api/user/information")
def user_info():
	user_idx = request.args.get("user_idx", "")
	response = requests.get(f"{INTERNAL_API}/user/{user_idx}")
@app.route("/v1/api/user/search")
def user_search():
	user_name = request.args.get("user_name", "")
	user_type = "public"
	response = requests.get(f"{INTERNAL_API}/user/search?user_name={user_name}&user_type={user_type}")
```
#### `user_info`
이용자가 전달한 `user_idx` 값을 내부 API의 URL 경로로 사용한다.
#### `user_search`
이용자가 전달한 `user_name` 값을 내부 API의 쿼리로 사용한다.
#### 문제점
`..`을 이용하여 경로를 조작하는 **Path Traversal**을 할 수 있다. 이외에도 `#`을 이용해 조작할 수 있다. `#`은 **Fragment Identifier**구분자로, 뒤에 붙는 문자열은 API 경로에서 생략된다.
### 웹 서비스의 요청 body에 이용자의 입력값이 포함
---
```py
from flask import Flask, request, session
import requests
from os import urandom
app = Flask(__name__)
app.secret_key = urandom(32)
INTERNAL_API = "http://127.0.0.1:8000/"
header = {"Content-Type": "application/x-www-form-urlencoded"}
@app.route("/v1/api/board/write", methods=["POST"])
def board_write():
    session["idx"] = "guest" # session idx를 guest로 설정합니다.
    title = request.form.get("title", "") # title 값을 form 데이터에서 가져옵니다.
    body = request.form.get("body", "") # body 값을 form 데이터에서 가져옵니다.
    data = f"title={title}&body={body}&user={session['idx']}" # 전송할 데이터를 구성합니다.
    response = requests.post(f"{INTERNAL_API}/board/write", headers=header, data=data) # INTERNAL API 에 이용자가 입력한 값을 HTTP BODY 데이터로 사용해서 요청합니다.
    return response.content # INTERNAL API 의 응답 결과를 반환합니다.
@app.route("/board/write", methods=["POST"])
def internal_board_write():
    # form 데이터로 입력받은 값을 JSON 형식으로 반환합니다.
    title = request.form.get("title", "")
    body = request.form.get("body", "")
    user = request.form.get("user", "")
    info = {
        "title": title,
        "body": body,
        "user": user,
    }
    return info
@app.route("/")
def index():
    # board_write 기능을 호출하기 위한 페이지입니다.
    return """
        <form action="/v1/api/board/write" method="POST">
            <input type="text" placeholder="title" name="title"/><br/>
            <input type="text" placeholder="body" name="body"/><br/>
            <input type="submit"/>
        </form>
    """
app.run(host="127.0.0.1", port=8000, debug=True)
```
#### `index`
board_write 기능을 호출하기 위한 인덱스 페이지이다.
#### `board_write`
이용자의 입력값을 HTTP Body에 포함하고 내부 API로 요청을 보낸다. 전송할 데이터를 구성할 때 세션 정보는 "guest"계정으로 설정한다.
#### `internal_board_write`
board_write 함수에서 요청하는 내부 API를 구현한 기능이다. 전달된 title, body, 계정 이름을 JSON 형식으로 변환하고 반환한다.
#### 문제점
데이터를 구성할 때 이용자의 입력값을 그대로 사용하기 때문에, `&`구분자를 사용해서 값을 변조할 수 있다. 예를 들어서 `&user=admin`을 삽입하게 되면 앞에서부터 파싱하기 때문에 user가 admin으로 설정할 수 있다.