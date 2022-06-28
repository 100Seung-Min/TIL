## Redis
### Redis
---
#### 명령어
* 데이터 조작
<table>
  <tr>
    <td>명령어</td>
    <td>구조</td>
    <td>설명</td>
  </tr>
  <tr>
    <td>GET</td>
    <td>GET key</td>
    <td>데이터 조회</td>
  </tr>
  <tr>
    <td>MGET</td>
    <td>MGET key [key...]</td>
    <td>여러 데이터를 조회</td>
  </tr>
  <tr>
    <td>SET</td>
    <td>SET key value</td>
    <td>새로운 데이터를 추가</td>
  </tr>
  <tr>
    <td>MSET</td>
    <td>MSET key value [key value ...]</td>
    <td>여러 데이터를 추가</td>
  </tr>
  <tr>
    <td>DEL</td>
    <td>DEL key [key ...]</td>
    <td>데이터 삭제</td>
  </tr>
  <tr>
    <td>EXISTS</td>
    <td>EXISTS key [key ...]</td>
    <td>데이터 유무 확인</td>
  </tr>
   <tr>
    <td>INCR</td>
    <td>INCR key</td>
    <td>데이터 값에 1 더함</td>
  </tr>
   <tr>
    <td>DECR</td>
    <td>DECR key</td>
    <td>데이터 값에 1 뺌</td>
  </tr>
</table>

* DBMS 관리
<table>
  <tr>
    <td>명령어</td>
    <td>구조</td>
    <td>설명</td>
  </tr>
  <tr>
    <td>INFO</td>
    <td>INFO [section]</td>
    <td>DBMS 정보 조회</td>
  </tr>
  <tr>
    <td>CONFIG GET</td>
    <td>CONFIG GET parameter</td>
    <td>설정 조회</td>
  </tr>
  <tr>
    <td>CONGIG SET</td>
    <td>CONFIG SET parameter value</td>
    <td>새로운 설정 입력</td>
  </tr>
</table>

### Redis Injection
---
* NodeJS에서 redis 사용
  ```js
  var express = require('express');
  var app = express();
  app.use(express.json());
  app.use(express.urlencoded( {extended : false } ));
  const redis = require("redis");
  const client = redis.createClient();
  app.get('/init', function(req,res) {
      // client.set("key", "value");
      client.set(req.query.uid, JSON.stringify({level: 'guest'}));
      res.send('ok')
  });
  var server = app.listen(3000, function(){
      console.log('app.listen');
  });
  ```
#### SSRF
redis는 기본적으로 인증 수단이 존재하지 않으며, "127.0.0.1"로 서비스를 바인딩하기 때문에 직접 접근하여 인증 과정 없이 명령어를 실행할 수 있다. 
* 공격 기법
redis는 유효하지 않은 명령어가 입력돼도 연결이 끊어지지 않고, 다음 명령어를 실행한다. 이로 인해 HTTP프로토콜을 이용하여 Body데이터에 실행할 명령어를 포함시켜 요청을 전송한다.
* 공격 기법 패치
HTTP프로토콜을 이용한 SSRF를 막고자 프로토콜에서 사용하는 주요 키워드가 명령어로 입력되면 연결을 끊어버려서 공격이 불가능 하도록 패치되었다. 그러나 이는 HTTP 프로토콜을 이용한 공격만 막기 때문에 다른 프로토콜을 이용한 공격에는 여전히 취약할 수 있다. 
#### django-redis-cache
Django에서 Redis를 사용한 캐시를 구현할 수 있는 파이썬 모듈로, 많이 사용하는 웹 프레임워크이다. `cache.set`함수를 사용해 키를 생성한다. 키의 값을 출력하면, Pickle로 덤프된 값을 볼 수 있다.
#### Serialize / Deserialize
Serialize(직렬화)는 객체 또는 데이터의 타입을 특정한 포맷을 가진 형태로 변환하는 작업을 말하고, Deserialize(역직렬화)는 직렬화된 데이터를 본래 객체 또는 데이터의 타입으로 되돌리는 것을 의미한다. 직렬화는 객체 및 데이터의 현재 상태와 타입들을 저장하고, 필요할 때 역직렬화를 통해 이들을 사용할 수 있다. 
* 공격
파이썬에서 직렬화와 역직렬화를 수행하는 대표적인 라이브러리로 pickle과 yaml이 존재한다. pickle모듈은 객체를 직렬화하여 파일에 저장할 수 있는 기능과 파일에 저장된 객체를 가져와 역직렬화하는 기능도 제공한다. `object.__reduce__()`는 객체 계층 구조를 unpickling 할 때 객체를 재구성하는 튜플을 반환해주는 메소드로, 호출 가능한 객체를 반환할 수 있다. 이 말은 즉, 호출 가능한 객체에 `system`과 같이 명령어를 실행할 수 있는 함수를 반환하면 시스템 명령어를 실행할 수 있다. 
#### Redis 명령어
* SAVE
redis는 메모리에 데이터를 저장하는 인 메모리 데이터베이스이다. 메모리는 휘발성이라는 특징을 갖고 있기 때문에 데이터 손실 방지를 위해 일정 시간마다 메모리 데이터를 파일 시스템에 저장한다. 
* SLAVEOF / REPLICAOF
다른 redis의 노드를 현재 명령어를 실행하는 노드의 마스터 노드로 지정할 수 있다. 지정한 노드와 연결을 맺으면, 마스터 노드의 데이터를 복제하고 저장한다. 
* MODULE LOAD
redis 4.0 버전부터 새로운 라이브러리를 추가해 사용할 수 있는 `module load`명령어를 제공한다. 해당 명령어를 통해 라이브러리를 로드하여 임의 코드를 실행할 수 있다. 
### 주의사항
---
#### 인증 체계
기본적으로 인증 과정 없이 조작이 가능한 DBMS라서 인증 과정을 추가해야 한다. "/etc/redis/redis.conf" 파일을 통해 DBMS의 설정을 관리한다. 추가로 6.0부터는 멀티 유저와 Access Control List를 통해 접근 제어를 설정할 수 있는 기능이 있다.
#### 바인딩
기본적인 바인딩 주소는 "127.0.0.1"로 설정되어있지만 설정 파일을 수정해 바인딩 주소를 변경할 수 있다. 
#### 중복 키 사용
키와 값이 하나의 쌍을 이루는 데이터를 저장하는 구조이며, 일반적으로 스키마/테이블, 콜렉션과 같이 특정한 영역으로 구분해 저장하지 않는다. 그래서 키 명칭이 중복되는 경우가 존재한다. 