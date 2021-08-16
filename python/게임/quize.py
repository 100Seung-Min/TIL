import pygame
from random import *

pygame.init()

# 화면크기
screen_width = 480
screen_height = 640
screen = pygame.display.set_mode((screen_width, screen_height))

# 화면 타이틀
pygame.display.set_caption("똥 피하기")

# FPS
clock = pygame.time.Clock()

# 1. 사용자 게임 초기화
background = pygame.image.load("C:/Users/user/Documents/GitHub/TIL/python/게임/background.png")

character = pygame.image.load("C:/Users/user/Documents/GitHub/TIL/python/게임/character.png")
character_size = character.get_rect().size
character_width = character_size[0]
character_height = character_size[1]
character_x_pos = (screen_width / 2) - (character_width / 2)
character_y_pos = screen_height - character_height

enemy = pygame.image.load("C:/Users/user/Documents/GitHub/TIL/python/게임/enemy.png")
enemy_size = enemy.get_rect().size
enemy_width = enemy_size[0]
enemy_height = enemy_size[1]
enemy_x_pos = randint(0, (screen_width - enemy_width))
enemy_y_pos = 0

to_x = 0
character_speed = 0.4
enemy_speed = 0.5

running = True
while running:
  dt = clock.tick(30) # 게임 화면의 초당 프레임 수

  # 2. 이벤트 처리
  for event in pygame.event.get():
    if event.type == pygame.QUIT: # 창이 닫히는 이벤트
      running = False

    if event.type == pygame.KEYDOWN:
      if event.key == pygame.K_RIGHT:
        to_x += character_speed
      elif event.key == pygame.K_LEFT:
        to_x -= character_speed

    if event.type == pygame.KEYUP:
      to_x = 0
  # 3. 게임 캐릭터 위치 정의
  character_x_pos += to_x * dt
  enemy_y_pos += enemy_speed * dt

  if character_x_pos < 0:
    character_x_pos = 0
  elif character_x_pos > screen_width - character_width:
    character_x_pos = screen_width - character_width

  if enemy_y_pos > screen_height:
    enemy_x_pos = enemy_x_pos = randint(0, (screen_width - enemy_width))
    enemy_y_pos = 0
  # 4. 충돌 처리
  character_rect = character.get_rect()
  character_rect.left = character_x_pos
  character_rect.top = character_y_pos

  enemy_rect = enemy.get_rect()
  enemy_rect.left = enemy_x_pos
  enemy_rect.top = enemy_y_pos

  if character_rect.colliderect(enemy_rect):
    print("충돌")
    running = False

  # 5. 화면에 그리기
  screen.blit(background,(0,0))
  screen.blit(character, (character_x_pos, character_y_pos))
  screen.blit(enemy, (enemy_x_pos, enemy_y_pos))

  pygame.display.update() # 게임화면 다시 그리기

pygame.quit()