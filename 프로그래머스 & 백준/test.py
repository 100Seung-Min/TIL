a, b, c = map(int, input().split())
if b > c:
  print(-1)
else:
  money = a
  while True:
    cnt = money//c
    money = (cnt*b) + a
    if money < c*cnt:
      print(cnt)
      break