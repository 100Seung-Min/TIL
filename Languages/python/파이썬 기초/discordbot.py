import asyncio
import discord

client = discord.Client()

##토큰의 값 저장
token = "ODQ3NzExMTI3MTg5MzIzODA2.YLCCgg.X2HVB7fJFTbcU06Hrf-NUz7foqw"

##디스코드 봇 준비
@client.event
async def on_ready():
  print("다음으로 로그인합니다")
  print(client.user.name)
  print(client.user.id)
  print("==============")

##메시지를 받았을 때
@client.event
async def on_message(message):
  if message.author.bot:
    return None
  if message.content.startswith('!안녕'):
    channel = message.channel
    await channel.send('반가워!')

client.run(token)