# # 모듈
# import theater_module
# theater_module.price(3)
# theater_module.price_morning(4)
# theater_module.price_soldier(5)
# import theater_module as mv
# mv.price(3)
# mv.price_morning(4)
# mv.price_soldier(5)
# from theater_module import *
# price(3)
# price_morning(4)
# price_soldier(5)
# from theater_module import price, price_morning
# price(5)
# price_morning(6)
# from theater_module import price_soldier as price
# price(5)

# # 패키지
# import travel.thailand
# from travel.thailand import ThailandPackage
# trip_to = travel.thailand.ThailandPackage()
# trip_to.detail()
# import travel.vietnam
# from travel.vietnam import VietnamPackage
# trip_to = VietnamPackage()
# trip_to.detail()

# # _all_
# from travel import *
# trip_to = vietnam.VietnamPackage()
# trip_to = thailand.ThailandPackage()
# trip_to.detail()

# # 패키지, 모듈 위치
# import inspect
# import random
# from travel import thailand
# print(inspect.getfile(random))
# print(inspect.getfile(thailand))

# from bs4 import BeautifulSoup
# soup = BeautifulSoup("<p>Some<b>bad<i>HTML")
# print(soup.prettify())

# # 내장함수
# # input: 입력 받는 함수
# language = input("무슨 언어를 좋아하세요?")
# print("{}은 아주 좋은 언어입니다!".format(language))
# # dir: 객체가 어떤 변수와 함수를 가지고 있는지
# print(dir())
# import random
# print(dir())
# import pickle
# print(dir())
# print(dir(random))
# lst = [1,2,3]
# print(dir(lst))
# name = "Jim"
# print(dir(name))

# # 외장함수
# # glob: 경로 내의 폴더 / 파일 목록 조회
# import glob
# print(glob.glob("*.py"))
# # os: 운영체제에서 제공하는 기본 기능
# import os
# print(os.getcwd())
# folder = "sample_dir"
# if os.path.exists(folder):
#   print("이미 존재하는 폴더입니다")
#   os.rmdir(folder)
#   print(folder, "폴더를 삭제하였습니다")
# else:
#   os.makedirs(folder)
#   print(folder, "폴더를 생성하였습니다.")
# print(os.listdir())
# # time, datetime: 시간관련
# # timedelta: 두 날짜 사이의 간격
# import time
# print(time.localtime())
# print(time.strftime("%y-%m-%d %H:%M:%S"))
# import datetime
# print("오늘 날짜는", datetime.date.today())
# today = datetime.date.today()
# td = datetime.timedelta(days=100)
# print("우리가 만난지 100일은", today+td)