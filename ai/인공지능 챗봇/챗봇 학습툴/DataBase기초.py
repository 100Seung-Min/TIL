import pymysql

db = None
try:  
  db = pymysql.connect(
    host='127.0.0.1',
    user='root',
    passwd='bsmin0417',
    db='seungmin',
    charset='utf8'
  )

  # # 테이블 생성 sql 정의
  # sql = '''
  # CREATE TABLE tb_student (
  #   id int primary key auto_increment not null,
  #   name varchar(32),
  #   age int,
  #   address varchar(32)
  # ) ENGINE=InnoDB DEFAULT CHARSET=utf8
  # '''

  # # 데이터 삽입 sql 정의
  # sql = '''
  # INSERT tb_student(name, age, address) VALUES ('Kei', 35, 'Korea')
  # '''

  # # 데이터 수정 sql 정의
  # id = 1 # 데이터 id(Primary Key)
  # sql = '''
  #   UPDATE tb_student set name="케이", age=36 where id=%d
  # '''%id

  # 데이터 삭제 sql 정의
  id = 1 # 데이터 id(Primary Key)
  sql = '''
    DELETE from tb_student where id=%d
  '''%id
  
  # sql 실행
  with db.cursor() as cursor:
    cursor.execute(sql)
  db.commit()
except Exception as e:
  print(e)
finally:
  if db is not None:
    db.close()