import discord
from random import *
from discord.ext import commands

bot=commands.Bot(command_prefix='./')

@bot.event
async def on_ready():
    print('로그인중입니다. ')
    print(f"봇={bot.user.name}로 연결중")
    print('연결이 완료되었습니다.')
    await bot.change_presence(status=discord.Status.online, activity=None)
@bot.command(aliases=['hi'])
async def 안녕(ctx):
  await ctx.send('안녕하세요.')
@bot.command()
async def 따라하기(ctx,*,text):
  await ctx.send(text)
    
bot.run("ODQ3NzExMTI3MTg5MzIzODA2.YLCCgg.MDyOcN8dBH0-zdRPQq8o2qwcORc") #보안을위해 다른 코드(to.py)에서 토큰값을 가져옴.