## HTTP (Hyper Text Transfer Protocol)

### HTTP란?
---
서버와 클라이언트의 데이터 교환을 **요청**과 **응답**으로 형식으로 정의한 프로토콜이다. 기본 매커니즘은 <u>**클라이언트가 서버에 요청하면, 서버가 응답**</u>을 하는 것이다. 웹 서버는 HTTP서버를 HTTP 서비스 포트에 대기시킨다. 일반적으로 TCP/80이나 TCP/8080이다.

### 네트워크 포트와 서비스 포트
---
네트워크 포트는 네트워크에서 서버와 클라이언트가 정보를 교환하는 추상화된 장소를 의미한다.   
   
서비스 포트는 네트워크 포트 중에서 특정 서비스가 점유하고 있는 포트를 말한다.   
   
포트로 데이터를 교환하는 방식은 **전송 계층**의 프로토콜을 따르는데 대표적으로 TCP와 UDP가 있다. 포트의 개수는 운영체제마다 다르지만, 현재는 모두 0번부터 65535번까지 총 65535개의 같은 수의 네트워크 포트를 사용한다. 포트 중 0번부터 1023번까지를 잘 알려진 포트, 특권 포트라고 한다. 예를 들어 22번은 SSH, 80은 HTTP, 443은 HTTPS가 할당되어 있다. 이 포트에 서비스를 실행하려면 관리자 권한이 필요하다.

### HTTP 메시지
---
메시지 안에는 클라이언트가 전송하는 HTTP요청, 서버가 반환하는 응답이 있다. 이 둘은 헤드와 바디로 구성된다.
#### HTTP 헤드
헤드의 각 줄은 CRLF로 구분되며, 첫 줄은 <u>**시작 줄**</u>, 나머지는 <u>**헤더**</u>라고 한다. 헤드의 끝은 CRLF 한 줄로 나타낸다. 헤더는 <u>**필드**</u>와 <u>**값**</u>으로 구성되며 HTTP 메시지 또는 바디의 속성을 나타낸다. 하나의 HTTP 메시지에는 0개 이상의 헤더가 있을 수 있다.

#### HTTP 바디
헤드의 끝을 나타내는 CRLF뒤, 모든 줄을 말한다. 클라이언트나 서버에게 전송하려는 데이터가 바디에 담긴다. 

### HTTP 요청
---
서버에게 특정 동작을 요구하는 메시지이다. 서버는 클라이언트의 요청이 적절할 때만 이를 처리한다.
#### 시작 줄
시작 줄은 <u>**메소드**</u>, <u>**요청 URI**</u>, <u>**HTTP버전**</u>으로 구성되고, 각각 띄어쓰기로 구분된다. **메소드**는 URI가 가리키는 리소스를 대상으로, 서버가 수행하길 바라는 동작을 나타낸다. HTTP표준에 정의된 메소드는 총 8개가 있다. 
* GET
  특정 데이터의 표시를 요청하는 것으로 오직 데이터를 받기만 한다.
* POST
  특정 리소스에 엔티티를 제출할 때 쓰며, 종종 서버의 상태변화나 부작용을 일으킬 수 있다. 
* PATCH
  리소스의 부분만 수정하는 데 쓰인다.
* PUT
  목적 리소스 모든 현재 표시를 요청 payload로 바꾼다.
* DELETE
  특정 리소스를 삭제한다.
* HEAD
  GET과 같지만, 응답 본문을 포함하지 않는다.
* OPTIONS
  목적 리소스의 통신을 설정하는 데 사용한다.
* TRACE
  목적 리소스의 경로를 따라 메시지 loop-back 테스트를 한다.
* CONNECT
  목적 리소스로 식별되는 서버로의 터널을 맺는다.

**요청 URI**는 메소드의 대상을, **HTTP버전**은 클라이언트가 사용하는 프로토콜의 버전을 나타낸다.

### HTTP 응답
요청에 대한 결과를 반환하는 메시지이다. 상태정보와, 클라이언트에게 전송할 리소스가 응답에 포함된다. 
#### 시작 줄
시작 줄은 <u>**HTTP버전**</u>, <u>**상태 코드**</u>, <u>**처리 사유**</u>로 구성되고, 각각 띄어쓰기로 구분된다. **HTTP 버전**은 서버에서 사용하는 HTTP프로토콜의 버전을 나타낸다. **상태 코드**는 요청에 대한 처리 결과를 세 자릿수로 나타낸다. **처리 사유**는 상태 코드가 발생한 이유를 짧게 기술한 것이다.
* 1XX
  요청을 받고, 처리가 진행중이다.
* 2XX
  요청이 성공적으로 처리되었다.
* 3XX
  요청을 처리하려면, 클라이언트가 추가 동작을 취해야한다.
* 4XX
  클라이언트가 잘못된 요청을 보내 처리에 실패했다.
* 5XX
  서버에 에러가 발생해 처리에 실패했다.