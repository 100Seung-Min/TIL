## NoSQL Injection
### NoSQL Injection
---
SQL Injection처럼 이용자의 입력값이 쿼리에 포함되면서 발생한다. MongoDB에서의 취약점은 주로 이용자의 입력 값에 대한 타입 검증이 불충분할 때 발생한다. SQL은 문자열, 정수, 날짜, 실수 등을 사용하는데, MongoDB는 오브젝트, 배열 타입을 사용할 수 있다. 주로 `$ne`를 이용하여 아닌 값들을 모두 불러와서 공격한다.
### Blined NoSQL Injection
---
데이터베이스의 정보를 알아낼 수 있다. 똑같이 참/거짓 결과를 통해 데이터베이스 정보를 알아낼 수 있다. 주로 `$expr`, `$regex`, `$text`, `$where`를 이용하여 공격한다.