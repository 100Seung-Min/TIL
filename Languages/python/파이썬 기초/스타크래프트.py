from random import *

class Unit:
  def __init__(self, name, hp, speed):
    self.name = name
    self.hp = hp
    self.speed = speed
    print("{} 유닛이 생성되었습니다".format(name))

  def move(self, location):
    print("{} : {} 방향으로 이동합니다. [속도 {}]".format(self.name, location, self.speed))
  
  def damaged(self, damage):
    print("{} : {} 데미지를 입었습니다.".format(self.name, damage))
    self.hp -= damage
    print("{} : 현재 체력은 {}입니다.".format(self.name, self.hp))
    if self.hp <= 0:
      print("{} : 파괴되었습니다.".format(self.name))

class Flyable:
  def __init__(self, flying_speed):
    self.flying_speed = flying_speed
  def fly(self, name, location):
    print("{} : {} 방향으로 날아갑니다 [속도 {}]".format(name, location,self.flying_speed))

class AttackUnit(Unit):
  def __init__(self, name, hp, speed, damage):
    Unit.__init__(self, name, hp, speed)
    self.damage = damage

  def attack(self, location):
    print("{} : {} 방향으로 적군을 공격 합니다. [공격력 {}]".format(self.name, location, self.damage))

class FlyableAttackUnit(AttackUnit, Flyable):
  def __init__(self, name, hp, damage, flying_speed):
      AttackUnit.__init__(self, name,hp, 0,damage)
      Flyable.__init__(self, flying_speed)
  def move(self, location):
    self.fly(self.name, location)

class Marine(AttackUnit):
  def __init__(self):
    AttackUnit.__init__(self, "마린", 40, 1, 5)

  def stimpack(self):
    if self.hp > 10:
      self.hp -= 10
      print("{} : 스팀팩을 사용합니다. (HP 10 감소)".format(self.name))
    else:
      print("{} : 체력이 부족하여 스팀팩을 사용하지 않습니다.".format(self.name))

class Tank(AttackUnit):
  seize_developed = False

  def __init__(self):
    AttackUnit.__init__(self, "탱크", 150, 1, 35)
    self.seize_mode = False

  def set_seize_mode(self):
    if Tank.seize_developed == False:
      return
    if self.seize_mode == False:
      print("{} : 시즈모드로 전환합니다.".format(self.name))
      self.damage *= 2
      self.seize_mode = True
    else:
      print("{} : 시즈모드를 해제합니다.".format(self.name))
      self.damage /= 2
      self.seize_mode = False

class Wraith(FlyableAttackUnit):
  def __init__(self):
    FlyableAttackUnit.__init__(self, "레이스", 80, 20, 5)
    self.clocked = False
  
  def clocking(self):
    if self.clocked == True:
      print("{} : 클로킹 모드 해제합니다.".format(self.name))
      self.clocked = False
    else:
      print("{} : 클로킹 모드 설정합니다.".format(self.name))
      self.clocked = True

def game_start():
  print("[알림] 새로운 게임을 시작합니다.")

def game_over():
  print("Player : gg")
  print("[Player]님이 게임에서 퇴장하셨습니다.")

game_start()

m1 = Marine()
m2 = Marine()
m3 = Marine()

t1 = Tank()
t2 = Tank()

w1 = Wraith()

attack_unit = []
attack_unit.append(m1)
attack_unit.append(m2)
attack_unit.append(m3)
attack_unit.append(t1)
attack_unit.append(t2)
attack_unit.append(w1)

for unit in attack_unit:
  unit.move("1시")

Tank.seize_developed = True
print("[알림] 탱크 시즈 모드 개발이 완료되었습니다.")

for unit in attack_unit:
  if isinstance(unit, Marine):
    unit.stimpack()
  elif isinstance(unit, Tank):
    unit.set_seize_mode()
  elif isinstance(unit, Wraith):
    unit.clocking()

for unit in attack_unit:
  unit.attack("1시")

for unit in attack_unit:
  unit.damaged(randint(5,21))

game_over()