import pymysql
import pandas as pd

db = None
try:  
  db = pymysql.connect(
    host='127.0.0.1',
    user='root',
    passwd='bsmin0417',
    db='seungmin',
    charset='utf8'
  )

  # 데이터에 db추가
  students = [
    {'name': 'Kei', 'age': 36, 'address': 'PUSAN'},
    {'name': 'Tony', 'age': 34, 'address': 'PUSAN'},
    {'name': 'Jaeyoo', 'age': 39, 'address': 'GWANGJU'},
    {'name': 'Grace', 'age': 28, 'address': 'SEOUL'},
    {'name': 'Jenny', 'age': 27, 'address': 'SEOUL'},
  ]

  for s in students:
    with db.cursor() as cursor:
      sql = '''
        INSERT tb_student(name, age, address) VALUES("%s", %d, "%s")
      '''%(s['name'], s['age'], s['address'])
      cursor.execute(sql)
  db.commit() # 커밋

  # 30대 학생만 조회
  cond_age = 30
  with db.cursor(pymysql.cursors.DictCursor) as cursor:
    sql = '''
      SELECT * FROM tb_student WHERE age > %d
    '''%cond_age
    cursor.execute(sql)
    results = cursor.fetchall()
  print(results)

  # 이름 검색
  cond_name = 'Grace'
  with db.cursor(pymysql.cursors.DictCursor) as cursor:
    sql = '''
      SELECT * FROM tb_student WHERE name="%s"
    '''%cond_name
    cursor.execute(sql)
    result = cursor.fetchone()
  print(result['name'], result['age'])

  # pandas 데이터프레임으로 표현
  df = pd.DataFrame(results)
  print(df)
except Exception as e:
  print(e)
finally:
  if db is not None:
    db.close()