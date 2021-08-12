# # 리스트
# subway = [10, 20, 30]
# print(subway)
# subway = ["유재석", "조세호", "박명수"]
# print(subway)
# print(subway.index("조세호"))
# subway.append("하하")
# print(subway)
# subway.insert(1, "정형돈")
# print(subway)
# print(subway.pop())
# print(subway)
# subway.append("유재석")
# print(subway.count("유재석"))
# num_list = [5, 2, 4, 3, 1]
# num_list.sort() #순서대로
# num_list.reverse() # 거꾸로정렬
# num_list.clear() # 다 지우기
# print(num_list)
# mix_list = ["조세호", 20, True]
# print(mix_list)
# num_list.extend(mix_list)
# print(num_list)

# # 사전
# cabinet = {3:"유재석", 100:"깁태호"}
# print(cabinet[3])
# print(cabinet[100])
# print(cabinet.get(3))
# print(cabinet[5]) # 실행 안됨
# print(cabinet.get(5)) # 실행 됨
# print(cabinet.get(5, "사용가능")) # 실행 됨, 없을시 사용가능
# print(3 in cabinet)
# print(5 in cabinet)
# cabinet = {"A-3":"유재석", "B-100":"깁태호"}
# print(cabinet["A-3"])
# print(cabinet["B-100"])
# print(cabinet)
# cabinet["A-3"] = "김종국"
# cabinet["C-20"] = "조세호"
# print(cabinet)
# del cabinet["A-3"]
# print(cabinet)
# print(cabinet.keys())
# print(cabinet.values())
# print(cabinet.items())
# cabinet.clear()
# print(cabinet)

# # 튜플
# menu = ("돈까스", "치즈까스")
# print(menu[0])
# print(menu[1])
# (name, age, hobby) = ("김종국", 20, "코딩")
# print(name, age, hobby)

# # 세트
# my_set = {1,2,3,3,3}
# print(my_set)
# java = {"유재석", "김태호", "양세형"}
# python = set(["유재석", "박명수"])
# print(java & python)
# print(java.intersection(python))
# print(java | python)
# print(java.union(python))
# print(java - python)
# print(java.difference(python))
# python.add("김태호")
# print(python)
# java.remove("김태호")
# print(java)

# # 자료구조의 변경
# menu = {"커피", "우유", "주스"}
# print(menu, type(menu))
# menu = list(menu)
# print(menu, type(menu))
# menu = tuple(menu)
# print(menu, type(menu))
# menu = set(menu)
# print(menu, type(menu))

# # 퀴즈
# from random  import *
# people = range(1,21)
# people = list(people)
# shuffle(people)
# winner = sample(people,4)
# print("-- 당첨자 발표 --")
# print("치킨 당첨자 : {0}".format(winner[0]))
# print("커피 당첨자 : {0}".format(winner[1:]))
# print("-- 축하합니다 --")
