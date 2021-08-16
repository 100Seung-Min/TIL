import pygame
import os

pygame.init()

# 화면크기
screen_width = 640
screen_height = 480
screen = pygame.display.set_mode((screen_width, screen_height))

# 화면 타이틀
pygame.display.set_caption("Pang")

# FPS
clock = pygame.time.Clock()

# 1. 사용자 게임 초기화
current_path = os.path.dirname(__file__) # 현재 파일 위치
image_path = os.path.join(current_path, "images")

# 배경
background = pygame.image.load(os.path.join(image_path, "background.png"))

# 스테이지
stage = pygame.image.load(os.path.join(image_path, "stage.png"))
stage_size = stage.get_rect().size
stage_height = stage_size[1]

# 캐릭터
character = pygame.image.load(os.path.join(image_path, "character.png"))
character_size = character.get_rect().size
character_width = character_size[0]
character_height = character_size[1]
character_x_pos = (screen_width / 2) - (character_width / 2)
character_y_pos = screen_height - character_height - stage_height

# 캐릭터 이동 방향, 속도
character_to_x = 0
character_speed = 5

# 무기 만들기
weapon = pygame.image.load(os.path.join(image_path, "weapon.png"))
weapon_size = weapon.get_rect().size
weapon_width = weapon_size[0]

# 무기 관리, 속도
weapons = []
weapon_speed = 10

running = True
while running:
  dt = clock.tick(60) # 게임 화면의 초당 프레임 수

  # 2. 이벤트 처리
  for event in pygame.event.get():
    if event.type == pygame.QUIT: # 창이 닫히는 이벤트
      running = False

    if event.type == pygame.KEYDOWN:
      if event.key == pygame.K_LEFT:
        character_to_x -= character_speed
      elif event.key == pygame.K_RIGHT:
        character_to_x += character_speed
      elif event.key == pygame.K_SPACE:
        weapon_x_pos = character_x_pos + (character_width / 2) - (weapon_width / 2)
        weapon_y_pos = character_y_pos
        weapons.append([weapon_x_pos, weapon_y_pos])
    elif event.type == pygame.KEYUP:
      if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT:
        character_to_x = 0


  # 3. 게임 캐릭터 위치 정의
  character_x_pos += character_to_x

  if character_x_pos < 0:
    character_x_pos = 0
  elif character_x_pos > screen_width - character_width:
    character_x_pos = screen_width - character_width

  # 무기 위치 조정
  weapons = [ [w[0], w[1] - weapon_speed] for w in weapons]

  # 무기 없애기
  weapons = [ [w[0], w[1]] for w in weapons if w[1] > 0]

  # 4. 충돌 처리

  # 5. 화면에 그리기
  screen.blit(background, (0,0))

  for weapon_x_pos, weapon_y_pos in weapons:
    screen.blit(weapon, (weapon_x_pos, weapon_y_pos))

  screen.blit(stage, (0, screen_height - stage_height))
  screen.blit(character, (character_x_pos, character_y_pos))

  pygame.display.update() # 게임화면 다시 그리기

pygame.quit()