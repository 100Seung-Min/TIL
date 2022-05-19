from Crypto.Util.number import bytes_to_long, long_to_bytes
from Crypto.Util.Padding import unpad
from Crypto.Cipher import AES
from pwn import *
import hashlib

# p = remote("host1.dreamhack.games", 13800)

# p.recvuntil("Prime: ")
# primeNum = int(p.recvline(), 16)

# p.recvline()
# p.sendlineafter(">>", "1")

# p.recvline()
# p.sendlineafter(">>", "1")

aes_key = hashlib.md5(str("1").encode()).digest()
cipher = AES.new(aes_key, AES.MODE_ECB)

# p.recvuntil("Alice: ")
# input = p.recvline()[:-1]
# log.info(b"Alice : " + input)
# flag = unpad(cipher.decrypt(bytes.fromhex(input.decode())), 16)
flag = unpad(cipher.decrypt(bytes.fromhex("e48e9174a9103e249f4bb809e13d58d49283e2438954799030be4854328adacbeb310c79bce3e91719f218158359af0d")), 16)
# p.recvuntil("Bob: ")
# input = p.recvline()[:-1]
# log.info(b"Bob : " + input)
# flag += unpad(cipher.decrypt(bytes.fromhex(input.decode())), 16)
flag += unpad(cipher.decrypt(bytes.fromhex("2a69648d494907e551b69b74676f2e528644a526e5f7bc8b6300f1bd8ad5f091a9e40939960ea5bd0ad2ceff23a14f96")), 16)
log.info(b"flag : " + flag)