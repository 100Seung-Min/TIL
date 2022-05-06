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

# 1. 사용자 게임 초기화

running = True
while running:
  dt = clock.tick(60) # 게임 화면의 초당 프레임 수

  # 2. 이벤트 처리
  for event in pygame.event.get():
    if event.type == pygame.QUIT: # 창이 닫히는 이벤트
      running = False

  # 3. 게임 캐릭터 위치 정의

  # 4. 충돌 처리

  # 5. 화면에 그리기

  pygame.display.update() # 게임화면 다시 그리기

pygame.quit()