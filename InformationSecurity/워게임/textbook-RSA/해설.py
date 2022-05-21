from Crypto.Util.number import bytes_to_long, long_to_bytes, inverse
from pwn import *

context.log_level="DEBUG"
p = remote("host1.dreamhack.games", 17772)
p.sendlineafter("info\n", "3")
p.recvuntil("N: ")
n = int(p.recvline()[:-1])

p.recvuntil("e: ")
e = int(p.recvline()[:-1])
p.recvuntil("FLAG:")
flag_enc = int(p.recvline()[:-1])

exploit_flag = (pow(2, e)*flag_enc)%n
log.info(str(exploit_flag))
p.sendlineafter("info\n", "2")
p.sendlineafter("(hex): ", hex(exploit_flag)[2:])
double_flag = int(p.recvline()[:-1])
flag = double_flag // 2

log.info("flag" + str(long_to_bytes(flag)))