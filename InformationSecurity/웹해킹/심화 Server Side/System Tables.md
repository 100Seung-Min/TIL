## System Tables
### System Tables
---
설정 및 계정 정보, 테이블과 컬럼 정보, 현재 실행되는 쿼리의 정보 등 다양한 정보를 포함하는 테이블이다.
#### MySQL
* 시스템 테이블
스키마와 데이터베이스가 같다. 처음에는 `information_schema`, `sql`, `perfomance_schema`, `sys` 데이터베이스가 있다. 
  ```sql
  show databases;
  ```
* 스키마 정보
  ```sql
  select TABLE_SCHEMA from information_schema.tables group by TABLE_SCHEMA;
  ```
* 테이블 정보
  ```sql
  select TABLE_SCHEMA, TABLE_NAME from information_schema.TABLES;
  ```
* 컬럼 정보
  ```sql
  select TABLE_SCHEMA, TABLE_NAME, COULMN_NAME from information_schema.COULMNS
  ```
* 실시간 실행 쿼리 정보
  ```sql
  select * from information_schema.PROCESSLIST;
  select user,current_statement from sys.session;
  ```
* DBMS 계정 정보
  ```sql
  select GRANTEE,PRIVILEGE_TYPE,IS_GRANTABLE from information_schema.USER_PRIVILEGES;
  select User, authentication_string from mysql.user;
  ```
#### MSSQL
* 시스템 테이블
  처음에는 `master`, `tempdb`, `model`, `msdb` 데이터베이스가 있다. 
  ```sql
  SELECT name FROM sys.databases
  ```
* 데이터베이스 정보
  `DB_NAME(num)`에서 0을 전달하면 현재 데이터베이스를 의미한다.
  ```sql
  SELECT name FROM master..sysdatabases;
  SELECT DB_NAME(1);
  ```
* 테이블 정보
  ```sql
  SELECT name FROM dreamhack..sysobjects WHERE xtype = 'U'; # xtype='U'는 이용자 정의 테이블을 의미한다.
  SELECT table_name FROM dreamhack.information_schema.tables;
  ```
* 컬럼 정보
  ```sql
  SELECT name FROM syscolumns WHERE id = (SELECT id FROM sysobjects WHERE name = 'users');
  SELECT table_name, column_name FROM dreamhack.information_schema.columns;
  ```
* DBMS 계정 정보
  ```sql
  SELECT name, password_hash FROM master.sys.sql_logins;
  SELECT * FROM master..syslogins;
  ```
#### PostgreSQL
* 시스템 테이블
  처음에는 `postgre`, `template1`, `template0` 데이터베이스가 있다. 
  ```sql
  select datname from pg_database;
  ```
* 스키마(카탈로그) 정보
  ```sql
  select nspname from pg_catalog.pg_namespace;
  ```
* 테이블 정보
  ```sql
  select table_name from information_schema.tables where table_schema='pg_catalog';
  select table_name from information_schema.tables where table_schema='information_schema';
  ```
* DBMS 계정 정보
  ```sql
  select usename, passwd from pg_catalog.pg_shadow;
  ```
* DBMS 설정 정보
  ```sql
  select name, setting from pg_catalog.pg_settings;
  ```
* 실시간 실행 쿼리 확인
  ```sql
  select usename, query from pg_catalog.pg_stat_activity;
  ```
* 테이블 정보
  ```sql
  select table_schema, table_name from information_schema.tables;
  ```
* 컬럼 정보
  ```sql
  select table_schema, table_name, column_name from information_schema.columns;
  ```
#### Oracle
* 데이터베이스 정보
  ```sql
  SELECT DISTINCT owner FROM all_tables
  SELECT owner, table_name FROM all_tables
  ```
* 컬럼 정보
  ```sql
  SELECT column_name FROM all_tab_columns WHERE table_name = 'users'
  ```
* DBMS 계정 정보
  ```sql
  SELECT * FROM all_users
  ```
#### SQLite
* 시스템 테이블
  ```sql
  .header on # 콘솔에서 실행 시 컬럼 헤더를 출력하기 위해 설정한다.
  select * from sqlite_master;
  ```