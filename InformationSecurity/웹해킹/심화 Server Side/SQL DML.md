## SQL DML 
### DML
---
#### SELECT
데이터를 조회하는 구문이다. 
* SELECT
해당 문자열을 시작으로, 조회하기 위한 표현식과 컬럼들에 대해 정의한다.
* FROM
데이터를 조회할 테이블의 이름이다.
* WHERE
조회할 데이터의 조건이다.
* ORDER BY
조회한 결과를 원하는 컬럼 기준으로 정렬한다.
* LIMIT
조회한 결과에서 행의 갯수와 오프셋을 지정한다.
```sql
예시) 
SELECT uid, title, boardcontent FROM boards WHERE boardcontent like '%abc%' ORDER BY uid DESC LIMIT 5
```
#### INSERT
데이터를 추가하는 구문이다.
* INSERT
해당 문자열을 시작으로, 추가할 테이블과 데이터를 정의한다.
* INTO
데이터를 추가할 테이블의 이름과 컬럼을 정의한다.
* VALUES
INTO 절에서 정의한 테이블의 컬럼에 명시한 데이터들을 추가한다.
```sql
예시)
INSERT INTO boards (title, boardcontent) VALUES ('title 1', 'content 1'), ('title 2', 'content 2');
INSERT INTO boards (title, boardcontent) VALUES ('title 1', (select upw from users where uid='admin'));
```
#### UPDATE
데이터를 수정하는 구문이다.
* UPDATE
해당 문자열을 시작으로, 수정할 테이블을 정의한다.
* SET
수정할 컬럼과 데이터를 정의한다.
* WHERE
수정할 행의 조건을 정의한다.
```sql
예시)
UPDATE boards SET boardcontent = "update content 2" WHERE title = 'title 1';
```
#### DELETE
데이터를 삭제하는 구문이다.
* DELETE
해당 문자열을 시작으로, 이후에 삭제할 테이블을 정의한다.
* FROM
삭제할 테이블을 정의한다.
* WHERE
삭제할 행의 조건을 정의한다.
```sql
예시)
DELETE FROM boards WHERE title = 'title 1';
```