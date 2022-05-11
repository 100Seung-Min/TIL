## NoRDBMS
### MongoDB
---
#### MongoDB 특징
1. 스키마를 정의하지 않아서, 콜렉션에 대한 정의가 필요하지 않는다.
2. JSON 형식으로 쿼리를 작성 할 수 있다.
3. _id 필드가 Primary Key 역할을 한다.
#### MongoDB 연산자
* Comparison
  * $eq
  지정된 값과 같은 값을 찾는다.
  * $in
  배열 안의 값들과 일치하는 값을 찾는다.
  * $ne
  지정된 값과 같지 않은 값을 찾는다.
  * $nin
  배열 안의 값들과 일치하지 않는 값을 찾는다.
* Logical
  * $and
  각각의 쿼리를 모두 만족하는 문서를 반환한다.
  * $not
  쿼리 식의 효과를 반전시킨다. 쿼리식과 일치하지 않는 문서를 반환한다.
  * $nor
  각각의 쿼리를 모두 만족하지 않는 문서가 반환된다.
  * $or
  각각의 쿼리 중 하나 이상 만족하는 문서가 반환된다.
* Element
  * $exists
  지정된 필드가 있는 문서를 찾는다.
  * $type
  지정된 필드가 지정된 유형인 문서를 선택한다.
* Evalution
  * $expr
  쿼리 언어 내에서 집계 식을 사용할 수 있다.
  * $regex
  지정된 정규식과 일치하는 문서를 선택한다.
  * $text
  지정된 텍스트를 검색한다.
#### MongoDB 기본 문법
* select -> find
* insert -> insert
* delete -> remove
* update -> update
안의 내용을 담을 경우 {key:value}형태로 담아서 전달한다.

### Redis
---
키-값의 쌍을 가진 데이터를 저장한다. 다른 데이터베이스와 다르게 메모리 기반의 DBMS이다. 
#### Redis 조회 및 조작 명령어
* GET
GET Key로 데이터를 조회
* MGET
MGET Key[Key ...]로 여러 데이터를 조회
* SET
SET Key Value로 새로운 데이터를 추가
* MSET 
MSET Key[Key ...]로 여러 데이터를 추가
* DEL
DEL Key[Key ...]로 데이터를 삭제
* EXISTS
EXISTS Key[Key ...]로 데이터 유무 확인
* INCR
INCR Key로 데이터 값에 1을 더함
* DECR
DECR Key로 데이터 값에 1을 뺌
* INFO
INFO [setion]으로 DBMS 정보 조회
* CONFIG GET
CONFIG GET parameter로 설정 조회
* CONFIG SET
CONFIG SET parameter value로 새로운 설정을 입력

### CouchDB
---
MongoDB와 같이 JSON 형태로 저장한다. 
#### CouchDB 메소드
* POST
새로운 레코드를 추가한다.
* GET
레코드를 조회한다.
* PUT
레코드를 업데이트한다.
* DELETE
레코드를 삭제한다.
#### CouchDB의 특수 구성 요소
`_`문자로 시작하는 URL, 필드는 특수 구성 요소를 나타낸다. 
* SERVER
  * /
  인스턴스에 대한 메타 정보를 반환한다.
  * /_all_dbs
  인스턴스의 데이터베이스 목록을 반환한다.
  * /_utils
  관리자페이지로 이동한다.
* DATABASE
  * /db
  지정된 데이터베이스에 대한 정보를 반환한다.
  * /{db}/_all_docs
  지정된 데이터베이스에 포함된 모든 문서를 반환한다.
  * {db}/find
  지정된 데이터베이스에서 JSON쿼리에 해당하는 모든 문서를 반환한다.
  