# # 문자열
# sentence = '나는 소년입니다'
# print(sentence)
# sentence2 = "파이썬은 쉬워요"
# print(sentence2)
# sentence3 = """
# 나는 소년이고,
# 파이썬은 쉬워요
# """
# print(sentence3)

# # 슬라이싱
# jumin = "990120-1234567"
# print("성별 : " + jumin[7])
# print("연 : " + jumin[0:2])
# print("월 : " + jumin[2:4])
# print("일 : " + jumin[4:6])
# print("생년월일 : " + jumin[:6])
# print("뒤 7자리 : " + jumin[7:])
# print("뒤 7자리(뒤에서 부터) : " + jumin[-7:])

# # 문자열 처리함수
# python = "Python is Amazing"
# print(python.lower()) #소문자
# print(python.upper()) #대문자
# print(python[0].isupper()) #대문자인지
# print(len(python)) # 문자길이
# print(python.replace("Python", "Java")) # 문자바꾸기
# index = python.index("n") # 문자위치 찾기
# print(index)
# index = python.index("n", index + 1) # 문자위치 찾기(지정)
# print(index)
# print(python.find("n")) # 문자위치 찾기
# print(python.find("Java")) # 문자위치 찾기
# print(python.index("Java")) # 문자위치 찾기
# print(python.count("n")) # 문자수 세기

# # 문자열 포맷
# print("a" + "b")
# print("a", "b")
# print("나는 %d살입니다" % 20)
# print("나는 %s을 좋아해요" % "파이썬")
# print("Apple은 %c로 시작해요" % "A")
# print("나는 %s색과 %s색을 좋아해요" % ("파란", "빨간"))
# print("나는 {}살입니다".format(20))
# print("나는 {}색과 {}색을 좋아해요".format("파란", "빨간"))
# print("나는 {1}색과 {0}색을 좋아해요".format("파란", "빨간"))
# print("나는 {age}살이며, {color}색을 좋아해요".format(age = 20, color = "빨간"))
# age = 20
# color = "빨간"
# print(f"나는 {age}살이며, {color}색을 좋아해요")

# # 탈출문자
# print("백문이 불여일견 \n백견이 불여일타")
# print("저는 '나도코딩'입니다")
# print('저는 "나도코딩"입니다')
# print("저는 \"나도코딩\"입니다")
# print("저는 \'나도코딩\'입니다")
# print("C:\\Users\\user\\Documents\\GitHub\\TIL\\python")
# print("Red Apple\rPine")
# print("Redd\bApple")
# print("Red\tApple")

# 퀴즈
# url = "http://naver.com"
# url = "http://daum.net"
# url = "http://google.com"
url = "http://youtube.com"
site = url.replace("http://","")
site = site[:site.index(".")]
password = site[:3] + str(len(site)) + str(site.count("e")) + "!"
print(f"{url}의 비밀번호는 {password}입니다")