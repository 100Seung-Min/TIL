from pwn import *
from Crypto.Util.number import getPrime, inverse, bytes_to_long, isPrime
from hashlib import sha1

# context.log_level = 'debug'

class DSA(object):
    def __init__(self, p, q, g, k, x):
        self.p = p
        self.q = q
        self.g = g
        self.x = x
        self.k = k

    def sign(self, msg):
        r = pow(self.g, self.k, self.p) % self.q
        h = bytes_to_long(sha1(msg).digest())
        s = inverse(self.k, self.q) * (h + self.x * r) % self.q
        return (r, s)
        
# p = process(["python3", "challenge.py"])
p = remote("host1.dreamhack.games", 21623)

def sign(msg):
    p.sendlineafter(b"Get Info\n", b"1")
    p.sendlineafter(b"Input message (hex): ", msg.hex().encode())
    r, s = p.recvline()[1:-2].split(b", ")
    return int(r.decode()), int(s.decode())

def verify(msg, r, s):
    p.sendlineafter(b"Get Info\n", b"2")
    p.sendlineafter(b"Input message (hex): ", msg.hex().encode())
    p.sendlineafter(b"Input signagure (r, s as decimal integer): ", (str(r) + str(", ") + str(s)).encode())
    res = p.recvline()[:-1].decode()
    if res == "Signature verification success":
        print(p.recvline()[:-1].decode())
    return

def print_info():
    p.sendlineafter(b"Get Info\n", b"3")
    p.recvuntil(b"p = ")
    dsa_p = p.recvline()[:-1].decode()
    p.recvuntil(b"q = ")
    dsa_q = p.recvline()[:-1].decode()
    p.recvuntil(b"g = ")
    dsa_g = p.recvline()[:-1].decode()
    p.recvuntil(b"y = ")
    dsa_y = p.recvline()[:-1].decode()
    p.recvuntil(b"token = b")
    token = p.recvline()[1:-2]
    return dsa_p, dsa_q, dsa_g, dsa_y, token

# 1.save token & DSA values
data = print_info()
dsa = DSA(int(data[0]), int(data[1]), int(data[2]), -1, -1)
token = data[4]
print(token)

# 2.sign "A"
r1, s1 = sign(b"A")

# 3.sign "B"
r2, s2 = sign(b"B")

# 4.calculate x
h1 = bytes_to_long(sha1(b"A").digest())
h2 = bytes_to_long(sha1(b"B").digest())
dsa.k = (h1 - h2) * inverse(s1 - s2, dsa.q) % dsa.q
dsa.x = inverse(dsa.k, dsa.q)

# 5.calculate signature of "token"
r, s = dsa.sign(token)

# 6.print flag
verify(token, r, s)


p.interactive()