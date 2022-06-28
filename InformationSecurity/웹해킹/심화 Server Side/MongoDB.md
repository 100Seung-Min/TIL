## MongoDB
### MongoDB
---
#### 특징
1. 스키마가 존재하지 않아서 각 테이블에 특별한 정의를 하지 않아도 된다.
2. JSON 형식으로 쿼리문을 작성할 수 있다.
3. `_id`필드가 기본키 역할을 한다.
#### 연산자 종류
* 비교 연산자
<table>
  <tr>
    <td>연산자명</td>
    <td>설명</td>
  </tr>
  <tr>
    <td>$eq</td>
    <td>지정된 값과 같은 값을 찾는다.</td>
  </tr>
  <tr>
    <td>$gt</td>
    <td>지정된 값보다 큰 값을 찾는다.</td>
  </tr>
  <tr>
    <td>$gte</td>
    <td>지정된 값보다 크거나 같은 값을 찾는다.</td>
  </tr>
  <tr>
    <td>$in</td>
    <td>배열 안의 값들과 일치하는 값을 찾는다.</td>
  </tr>
  <tr>
    <td>$lt</td>
    <td>지정된 값보다 작은 값을 찾는다.</td>
  </tr>
  <tr>
    <td>$lte</td>
    <td>지정된 값보다 작거나 같은 값을 찾는다.</td>
  </tr>
  <tr>
    <td>$ne</td>
    <td>지정된 값과 같지 않은 값을 찾는다.</td>
  </tr>
  <tr>
    <td>$nin</td>
    <td>배열 안의 값들과 일치하지 않는 값을 찾는다.</td>
  </tr>
</table>

* 논리 연산자
<table>
  <tr>
    <td>연산자명</td>
    <td>설명</td>
  </tr>
  <tr>
    <td>$and</td>
    <td>논리적 AND, 각각의 쿼리를 모두 만족하는 문서가 반환된다.</td>
  </tr>
  <tr>
    <td>$not</td>
    <td>쿼리 식의 효과를 반전시킨다. 쿼리 식과 일치하지 않는 문서를 반환한다.</td>
  </tr>
  <tr>
    <td>$nor</td>
    <td>논리적 NOR, 각각의 쿼리를 모두 만족하지 않는 문서가 반환된다.</td>
  </tr>
  <tr>
    <td>$or</td>
    <td>논리적 OR, 각각의 쿼리 중 하나 이상 만족하는 문서가 반환된다.</td>
  </tr>
</table>

* 원소 연산자
<table>
  <tr>
    <td>연산자명</td>
    <td>설명</td>
  </tr>
  <tr>
    <td>$exists</td>
    <td>지정된 필드가 있는 문서를 찾는다.</td>
  </tr>
  <tr>
    <td>$type</td>
    <td>지정된 필드가 지정된 유형인 문서를 선택한다.</td>
  </tr>
</table>

* 평가 연산자
<table>
  <tr>
    <td>연산자명</td>
    <td>설명</td>
  </tr>
  <tr>
    <td>$expr</td>
    <td>쿼리 언어 내에서 집계 식을 사용할 수 있다.</td>
  </tr>
  <tr>
    <td>$jsonSchema</td>
    <td>주어진 JSON 스키마에 대해 문서를 검증한다.</td>
  </tr>
  <tr>
    <td>$mod</td>
    <td>필드 값에 대해 mod 연산을 수행하고, 지정된 결과를 가진 문서를 선택한다.</td>
  </tr>
  <tr>
    <td>$regex</td>
    <td>지정한 정규식과 일치하는 문서를 선택한다.</td>
  </tr>
  <tr>
    <td>$text</td>
    <td>지정한 텍스트를 검색한다.</td>
  </tr>
  <tr>
    <td>$where</td>
    <td>지정한 자바스크립트 식을 만족하는 문서와 일치한다.</td>
  </tr>
</table>

### MongoDB Injection
---
* GET 방식 서버
  ```py
  const express = require('express');
  const app = express();
  app.get('/', function(req,res) {
      console.log('data:', req.query.data);
      console.log('type:', typeof req.query.data);
      res.send('hello world');
  });
  const server = app.listen(3000, function(){
      console.log('app.listen');
  });
  ```
* POST 방식 서버
  ```py
  const express = require('express');
  const app = express();
  app.use(express.json());
  app.use(express.urlencoded( {extended : false } ));
  app.get('/', function(req,res) {
      res.send('hello world');
  });
  app.post('/post', function(req,res) {
      console.log('data:', req.body.data);
      console.log('type:', typeof req.body.data);
      res.send({"status":"ok"});
  });
  const server = app.listen(3000, function(){
      console.log('app.listen');
  });
  ```
모두 입력 타입을 검사하지 않아서 모든 타입이 들어갈 수 있다.
* 공격용 서버
  ```py
  const express = require('express');
  const app = express();
  const mongoose = require('mongoose');
  const db = mongoose.connection;
  mongoose.connect('mongodb://localhost:27017/', { useNewUrlParser: true, useUnifiedTopology: true });
  app.get('/query', function(req,res) {
      db.collection('user').find({
          'uid': req.query.uid,
          'upw': req.query.upw
      }).toArray(function(err, result) {
          if (err) throw err;
          res.send(result);
    });
  });
  const server = app.listen(3000, function(){
      console.log('app.listen');
  });
  ```
쿼리에 `uid[$ne]=a&upw[$ne]=a`를 작성하여 `uid`와 `upw`가 a가 아닌 계정을 조회한다.

### MongoDB Blind Injection
---
* regex
정규식을 사용할 수 있는 `regex`를 이용하여 공격한다.
* where
자바스크립트 식과 함께 데이터를 비교할 수 있다. 단, 해당 연산자는 필드 안에서 사용할 수 없다. `{$where: "this.upw.substring(0,1)=='a'"}`와 같이 사용할 수 있다. 또는 `sleep()`함수를 넣어서 확인할 수 있다. 또한 일부러 에러를 줘서 앞에 값이 참일 경우에만 에러를 확인하여 공격할 수 있다.