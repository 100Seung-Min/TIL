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

# 공 만들기
ball_images = [
  pygame.image.load(os.path.join(image_path, "ballon1.png")),
  pygame.image.load(os.path.join(image_path, "ballon2.png")),
  pygame.image.load(os.path.join(image_path, "ballon3.png")),
  pygame.image.load(os.path.join(image_path, "ballon4.png"))]

# 공 최초 속도
ball_speed_y = [-18, -15, -12, -9]

# 공들
balls = []
balls.append({
  "pos_x":50,
  "pos_y":50,
  "img_idx":0,
  "to_x":3,
  "to_y":-6,
  "init_spd_y":ball_speed_y[0]})

# 사라지는 공, 무기
weapon_to_remove = -1
ball_to_remove = -1

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

  # 공 위치 정의
  for ball_idx, ball_val in enumerate(balls):
    ball_pos_x = ball_val["pos_x"]
    ball_pos_y = ball_val["pos_y"]
    ball_img_idx = ball_val["img_idx"]

    ball_size = ball_images[ball_img_idx].get_rect().size
    ball_width = ball_size[0]
    ball_height = ball_size[1]

    # 가로효과
    if ball_pos_x < 0 or ball_pos_x > screen_width - ball_width:
      ball_val["to_x"] = ball_val["to_x"] * -1

    # 세로 효과
    if ball_pos_y >= screen_height - stage_height - ball_height:
      ball_val["to_y"] = ball_val["init_spd_y"]
    else:
      ball_val["to_y"] += 0.5
    ball_val["pos_x"] += ball_val["to_x"]
    ball_val["pos_y"] += ball_val["to_y"]

  # 4. 충돌 처리
  character_rect = character.get_rect()
  character_rect.left = character_x_pos
  character_rect.top = character_y_pos

  for ball_idx, ball_val in enumerate(balls):
    ball_pos_x = ball_val["pos_x"]
    ball_pos_y = ball_val["pos_y"]
    ball_img_idx = ball_val["img_idx"]

    ball_rect = ball_images[ball_img_idx].get_rect()
    ball_rect.left = ball_pos_x
    ball_rect.top = ball_pos_y

    if character_rect.colliderect(ball_rect):
      running = False
      break

    for weapon_idx, weapon_val in enumerate(weapons):
      weapon_pos_x = weapon_val[0]
      weapon_pos_y = weapon_val[1]

      weapon_rect = weapon.get_rect()
      weapon_rect.left = weapon_pos_x
      weapon_rect.top = weapon_pos_y

      if weapon_rect.colliderect(ball_rect):
        weapon_to_remove = weapon_idx
        ball_to_remove = ball_idx

        if ball_img_idx < 3:
          ball_width = ball_rect.size[0]
          ball_height = ball_rect.size[1]

          small_ball_rect = ball_images[ball_img_idx + 1].get_rect()
          small_ball_width = small_ball_rect.size[0]
          small_ball_height = small_ball_rect.size[1]

          balls.append({
              "pos_x":ball_pos_x + (ball_width / 2) - (small_ball_width / 2),
              "pos_y":ball_pos_y + (ball_height / 2) - (small_ball_height / 2),
              "img_idx":ball_img_idx + 1,
              "to_x":-3,
              "to_y":-6,
              "init_spd_y":ball_speed_y[ball_img_idx + 1]})
          balls.append({ 
              "pos_x":ball_pos_x + (ball_width / 2) - (small_ball_width / 2),
              "pos_y":ball_pos_y + (ball_height / 2) - (small_ball_height / 2),
              "img_idx":ball_img_idx + 1,
              "to_x":3,
              "to_y":-6,
              "init_spd_y":ball_speed_y[ball_img_idx + 1]})
        break

  # 공, 무기 없애기
  if ball_to_remove > -1:
    del balls[ball_to_remove]
    ball_to_remove = -1
  if weapon_to_remove > -1:
    del weapons[weapon_to_remove]
    weapon_to_remove = -1

  # 5. 화면에 그리기
  screen.blit(background, (0,0))

  for weapon_x_pos, weapon_y_pos in weapons:
    screen.blit(weapon, (weapon_x_pos, weapon_y_pos))

  for idx, val in enumerate(balls):
    ball_pos_x = val["pos_x"]
    ball_pos_y = val["pos_y"]
    ball_img_idx = val["img_idx"]
    screen.blit(ball_images[ball_img_idx], (ball_pos_x, ball_pos_y))

  screen.blit(stage, (0, screen_height - stage_height))
  screen.blit(character, (character_x_pos, character_y_pos))

  pygame.display.update() # 게임화면 다시 그리기

pygame.quit()