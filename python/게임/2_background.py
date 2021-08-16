import pygame

pygame.init()

# 화면크기
screen_width = 480
screen_height = 640
screen = pygame.display.set_mode((screen_width, screen_height))

# 화면 타이틀
pygame.display.set_caption("Gun Game")

# 배경 이미지 불러오기
background = pygame.image.load("C:/Users/user/Documents/GitHub/TIL/python/게임/background.png")

# 이벤트 루프
running = True
while running:
  for event in pygame.event.get():
    if event.type == pygame.QUIT: # 창이 닫히는 이벤트
      running = False
  # screen.fill((0,0,255)) # rgb값으로 색채우기
  screen.blit(background, (0, 0)) # 배경 그리기
  pygame.display.update() # 게임화면 다시 그리기

# pygame 종료
pygame.quit()