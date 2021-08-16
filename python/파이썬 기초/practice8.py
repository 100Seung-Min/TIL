# # 클래스, __init__
# class unit:
#   def __init__(self, name, hp, speed):
#     self.name = name
#     self.hp = hp
#     self.speed = speed
#     self.damage = damage
#     print("{} 유닛이 생성 되었습니다".format(self.name))
#     print("체력 {}, 공격력 {}".format(hp, damage))
# marine1 = unit("마린", 40, 5)
# tank1 = unit("탱크", 150, 35)
#   def move(self, location):
#     print("[지상 유닛 이동]")
#     print("{} : {} 방향으로 이동합니다 [속도 {}]".format(self.name, location, self.speed))

# # 멤버변수
# wraith1 = unit("레이스", 80, 5)
# print("유닛 이름 : {}, 공격력 : {}".format(wraith1.name, wraith1.damage))
# wraith2 = unit("빼앗은 레이스", 80, 5)
# wraith2.clocking = True
# if wraith2.clocking == True:
#   print("{}는 현재 클로킹 상태입니다".format(wraith2.name))

# # 메소드, 상속
# class attackunit(unit):
#   def __init__(self, name, hp, speed,damage):
#     unit.__init__(self,name,hp, speed)
#     self.damage = damage
#   def attack(self, location):
#     print("{} : {} 방향으로 적군을 공격합니다 [공격력 {}]".format(self.name, location, self.damage))
#   def damaged(self, damage):
#     print("{} : {}데미지를 입었습니다".format(self.name, damage))
#     self.hp -= damage
#     print("{} : 현재 체력은 {}입니다".format(self.name, self.hp))
#     if self.hp <= 0:
#       print("{} : 파괴되었습니다".format(self.name))
# firebat1 = attackunit("파이어뱃", 50, 16)
# firebat1.attack("5시")
# firebat1.damaged(25)
# firebat1.damaged(25)

# # 다중 속성
# class flyable:
#   def __init__(self, flying_speed):
#     self.flying_speed = flying_speed
#   def fly(self, name, location):
#     print("{} : {} 방향으로 날아갑니다 [속도 {}]".format(name, location,self.flying_speed))
# class flyableattackunit(attackunit, flyable):
#   def __init__(self, name, hp, damage, flying_speed):
#       attackunit.__init__(self, name,hp, 0,damage)
#       flyable.__init__(self, flying_speed)
#   def move(self, location):
#     print("[공중 유닛 이동]")
#     self.fly(self.name, location)
# valkyrie = flyableattackunit("발키리", 200, 6, 5)
# valkyrie.fly(valkyrie.name, "3시")

# # 연산자 오버로딩
# vulture = attackunit("벌쳐", 80, 10, 20)
# battlecruiser = flyableattackunit("배틀크루저", 500, 25, 3)
# vulture.move("11시")
# battlecruiser.move("9시")

# # pass, super
# class buildingunit(unit):
#   def __init__(self, name, hp, location):
#     super().__init__(name, hp, 0)
# supply_depot = buildingunit("서플라이 디폿", 500, "7시")
# def game_start():
#   print("[알림] 새로운 게임을 시작합니다")
# def game_over():
#   pass
# class unit:
#   def __init__(self):
#     print("unit 생성자")
# class flyable:
#   def __init__(self):
#     print("flyable 생성자")
# class flyableunit(unit, flyable):
#   def __init__(self):
#     super().__init__()

# 퀴즈
class House:
  def __init__(self, location, house_type, deal_type, price, completion_year):
    self.location = location
    self.house_type = house_type
    self.deal_type = deal_type
    self.price = price
    self.completion_year = completion_year
  def show_detail(self):
    print(self.location, self.house_type, self.deal_type, self.price, self.completion_year)

houses = []
house1 = House("강남", "아파트", "매매", "10억", "2010년")
house2 = House("마포", "오피스텔", "전세", "5억", "2007년")
house3 = House("송파", "빌라", "월세", "500/50", "2000년")
houses.append(house1)
houses.append(house2)
houses.append(house3)

print("총 {}대의 매물이 있습니다.".format(len(houses)))
for house in houses:
  house.show_detail()