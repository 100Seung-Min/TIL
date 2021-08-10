# # 연산자
# print(1 + 1)
# print(3 - 2)
# print(5 * 2)
# print(6 / 3)
# print(2 ** 3)
# print(5 % 3)
# print(5 // 3)
# print(10 > 3)
# print(4 >= 7)
# print(10 < 3)
# print(5 <= 5)
# print(3 == 3)
# print(4 == 2)
# print(3 + 4 == 7)
# print(1 != 3)
# print(not(1 != 3))
# print((3 > 0) and (3 < 5))
# print((3 > 0) & (3 < 5))
# print((3 > 0) or (3 > 5))
# print((3 > 0) | (3 > 5))
# print(5 > 4 > 3)
# print(5 > 4 > 7)

# #간단한 수식
# print(2 + 3 * 4)
# print((2 + 3) * 4)
# number = 2 + 3 * 4
# print(number)
# number = number + 2
# print(number)
# number += 2
# print(number)
# number *= 2
# print(number)
# number /= 2
# print(number)
# number -= 2
# print(number)
# number %= 2
# print(number)

# # 숫자처리 함수
# print(abs(-5)) #절대값
# print(pow(4,2)) # 제곱
# print(max(5,12)) # 최대값
# print(min(5,12)) # 최소값
# print(round(3.14)) # 반올림
# print(round(4.99)) # 반올림

# # 수학라이브러리
# from math import *
# print(floor(4.99)) # 내림
# print(ceil(3.14)) # 올림
# print(sqrt(16)) # 제곱근

# # 랜덤함수
# from random import *
# print(random())
# print(random() * 10)
# print(int(random() * 10))
# print(int(random() * 10) + 1)

# # 로또번호
# print(int(random() * 45) + 1)
# print(int(random() * 45) + 1)
# print(int(random() * 45) + 1)
# print(int(random() * 45) + 1)
# print(int(random() * 45) + 1)
# print(int(random() * 45) + 1)

# print(randrange(1,46))
# print(randrange(1,46))
# print(randrange(1,46))
# print(randrange(1,46))
# print(randrange(1,46))
# print(randrange(1,46))

# print(randint(1,45))
# print(randint(1,45))
# print(randint(1,45))
# print(randint(1,45))
# print(randint(1,45))
# print(randint(1,45))

#퀴즈
from random import *
day = randint(4,28)
print("오프라인 스터디 모임 날짜는 매월", day, "일로 선정되었습니다")