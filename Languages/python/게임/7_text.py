import pygame

pygame.init()

# 화면크기
screen_width = 480
screen_height = 640
screen = pygame.display.set_mode((screen_width, screen_height))

# 화면 타이틀
pygame.display.set_caption("Gun Game")

# FPS
clock = pygame.time.Clock()

# 배경 이미지 불러오기
background = pygame.image.load("C:/Users/user/Documents/GitHub/TIL/python/게임/background.png")

# 캐릭터(스프라이트) 불러오기
character = pygame.image.load("C:/Users/user/Documents/GitHub/TIL/python/게임/character.png")
character_size = character.get_rect().size # 이미지의 크기를 구함
character_width = character_size[0] # 가로 크기
character_height = character_size[1] # 세로 크기
character_x_pos = (screen_width / 2) - (character_width / 2) # 화면 가로 절반에 위치
character_y_pos = screen_height - character_height # 화면 세로 가장 밑

# 이동할 좌표
to_x = 0
to_y = 0

# 이동 속도
character_speed = 0.6

# 적 캐릭터
enemy = pygame.image.load("C:/Users/user/Documents/GitHub/TIL/python/게임/enemy.png")
enemy_size = enemy.get_rect().size # 이미지의 크기를 구함
enemy_width = enemy_size[0] # 가로 크기
enemy_height = enemy_size[1] # 세로 크기
enemy_x_pos = (screen_width / 2) - (enemy_width / 2) # 화면 가로 절반에 위치
enemy_y_pos = (screen_height / 2) - (enemy_height / 2) # 화면 세로 가장 밑

# 폰트 정의
game_font = pygame.font.Font(None, 40) # 폰트 객체 생성

# 총 시간
total_time = 10

# 시작 시간
start_ticks = pygame.time.get_ticks()

# 이벤트 루프
running = True
while running:
  dt = clock.tick(60) # 게임 화면의 초당 프레임 수
  for event in pygame.event.get():
    if event.type == pygame.QUIT: # 창이 닫히는 이벤트
      running = False

    if event.type == pygame.KEYDOWN: # 키를 눌렀는지
      if event.key == pygame.K_LEFT:
        to_x -= character_speed
      elif event.key == pygame.K_RIGHT:
        to_x += character_speed
      elif event.key == pygame.K_UP:
        to_y -= character_speed
      elif event.key == pygame.K_DOWN:
        to_y += character_speed

    if event.type == pygame.KEYUP: # 키를 땠는지
      if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT:
        to_x = 0
      elif event.key == pygame.K_UP or event.key == pygame.K_DOWN:
        to_y = 0

  character_x_pos += to_x * dt
  character_y_pos += to_y * dt

  # 가로 경계값 
  if character_x_pos < 0:
    character_x_pos = 0
  elif character_x_pos > screen_width - character_width:
    character_x_pos = screen_width - character_width
  
  # 세로 경계값
  if character_y_pos < 0:
    character_y_pos = 0
  elif character_y_pos > screen_height - character_height:
    character_y_pos = screen_height - character_height

  # rect 업데이트
  character_rect = character.get_rect()
  character_rect.left = character_x_pos
  character_rect.top = character_y_pos
  enemy_rect = enemy.get_rect()
  enemy_rect.left = enemy_x_pos
  enemy_rect.top = enemy_y_pos

  # 충돌 체크
  if character_rect.colliderect(enemy_rect):
    print("충돌")
    running = False

  screen.blit(background, (0, 0)) # 배경 그리기
  screen.blit(character, (character_x_pos, character_y_pos)) # 캐릭터 그리기
  screen.blit(enemy, (enemy_x_pos, enemy_y_pos)) # 적 그리기
  elapsed_time = (pygame.time.get_ticks() - start_ticks) / 1000 # 경과시간 계산(초 단위로 표시)
  timer = game_font.render(str(int(total_time - elapsed_time)), True, (255,255,255)) # 글자 설정(글자, True, 글자 색)
  screen.blit(timer,(10,10)) # 시간 띄우기
  pygame.display.update() # 게임화면 다시 그리기

  # timeout
  if total_time - elapsed_time <= 0:
    print("타임아웃")
    running = False

# 잠시 대기
pygame.time.delay(2000)

# pygame 종료
pygame.quit()