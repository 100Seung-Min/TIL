## SOP (Same Origin Policy)
### SOP란?
---
**이용자가 웹서버에 접속할 때, 브라우저는 해당 웹서비스에서 사용하는 인증 정보인 쿠키를 HTTP 헤더에 포함시켜 전달한다.** 이는 사이트에 직접 접속할 뿐만 아니라 타 사이트에 접근할 때도 쿠키를 전송한다. 그래서 악의적인 페이지가 대상 사이트에 HTTP요청을 보내고, HTTP응답 정보를 획득 하는 코드를 실행 할 수 있다. 그래서 클라이언트가 가져온 데이터를 악의적인 페이지에서 볼 수 없도록 하는것이 **동일출처정책**(SOP)이다.
#### SOP의 Origin 구분
오리진은 **프로토콜**, **포트**, **호스트**로 구성된다. 이 오리진이 모두 일치해야 동일한 오리진이라고 한다. 
#### SOP 실습
`https://dreamhack.io`에서 실습
* Same Origin
  ```js
  sameNewWindow = window.open('https://dreamhack.io/lecture');
  console.log(sameNewWindow.location.href);
  결과: https://dreamhack.io/lecture
  ```
* Cross Origin
  ```js
  crossNewWindow = window.open('https://theori.io');
  console.log(crossNewWindow.location.href);
  결과: Origin 오류 발생
  ```
Cross Origin의 데이터를 읽으려고 할 때는 오류가 발생하지만 데이터를 쓰는 것은 오류가 나지 않는다. 

<br><br>

## CORS (Cross Origin Resource Sharing)
### SOP의 완화
---
`<img>`, `<style>`, `<script>`등의 태그는 SOP의 영향을 받지 않는다. 그리고 **웹서비스에서 SOP를 완화하여 다른 출처의 데이터를 처리**해야 하는 경우가 있다. 이러한 상황에서 사용하는 공유방법이 **교차 출처 리소스 공유** (CORS)이다. 공유하는 방법은 CORS와 관련된 HTTP헤더를 추가하여 전송하는 방법을 사용한다. 이 외에도 **JSONP** (JSON with Padding)방법을 통해 CORS를 대체할 수 있다. 
### CORS란?
---
HTTP헤더에 기반하여 Cross Origin 간에 리소스를 공유하는 방법이다. 발신측에서 Cross헤더를 설정하면 요청하면, 수신측에서 헤더를 구분해 정해진 규칙에 맞게 데이터를 가져갈 수 있도록 설정한다. 발신측에서 POST를 보내도, OPTIONS메소드를 가진 HTTP요청이 전달되고, 이를 **CORS preflight**라고 한다. 위 과정이 끝나면 브라우저는 수신측의 응답이, 발신측의 요청과 상응하는지 확인한다. 그 후에야 POST요청을 보낸다.
#### CORS의 Header
* **Access-Control-Allow-Origin** : 헤더 값에 해당하는 Origin에서 들어오는 요청만 처리한다.
* **Access-Control-Allow-Methods** : 헤더 값에 해당하는 메소드의 요청만 처리한다.
* **Access-Control-Allow-Credentials** : 쿠키 사용 여부를 판단한다.
* **Access-Control-Allow-Headers** : 헤더 값에 해당하는 헤더의 사용 가능 여부를 나타낸다.
### JSONP란?
`<script>`태그를 이용해서 Cross Origin을 불러오는 것이다. 자바스크립트의 코드로 인식하기 때문에 **Callback 함수**를 활용해야한다. 하지만 JSONP는 CORS가 나오기 전에 사용하던 것으로 최근에는 대부분 사용하지 않는다.