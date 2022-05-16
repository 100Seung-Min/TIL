from Crypto.Cipher import DES
# Initial/Final Permutation Table
IPT = [58, 50, 42, 34, 26, 18, 10, 2,
       60, 52, 44, 36, 28, 20, 12, 4,
       62, 54, 46, 38, 30, 22, 14, 6,
       64, 56, 48, 40, 32, 24, 16, 8,
       57, 49, 41, 33, 25, 17, 9, 1,
       59, 51, 43, 35, 27, 19, 11, 3,
       61, 53, 45, 37, 29, 21, 13, 5,
       63, 55, 47, 39, 31, 23, 15, 7]
FPT = [40, 8, 48, 16, 56, 24, 64, 32,
       39, 7, 47, 15, 55, 23, 63, 31,
       38, 6, 46, 14, 54, 22, 62, 30,
       37, 5, 45, 13, 53, 21, 61, 29,
       36, 4, 44, 12, 52, 20, 60, 28,
       35, 3, 43, 11, 51, 19, 59, 27,
       34, 2, 42, 10, 50, 18, 58, 26,
       33, 1, 41, 9, 49, 17, 57, 25]
# Expansion P-Box Table
EPT = [32, 1, 2, 3, 4, 5,
       4, 5, 6, 7, 8, 9,
       8, 9, 10, 11, 12, 13,
       12, 13, 14, 15, 16, 17,
       16, 17, 18, 19, 20, 21,
       20, 21, 22, 23, 24, 25,
       24, 25, 26, 27, 28, 29,
       28, 29, 30, 31, 32, 1]
# S-Boxs
S = [
    # S1
    [
        [14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7],
        [0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8],
        [4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0],
        [15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13]
    ],
    # S2
    [
        [15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10],
        [3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5],
        [0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15],
        [13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9],
    ],
    # S3
    [
        [10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8],
        [13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1],
        [13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7],
        [1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12],
    ],
    # S4
    [
        [7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15],
        [13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9],
        [10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4],
        [3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14],
    ],
    # S5
    [
        [2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9],
        [14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6],
        [4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14],
        [11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3],
    ],
    # S6
    [
        [12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11],
        [10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8],
        [9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6],
        [4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13],
    ],
    # S7
    [
        [4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1],
        [13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6],
        [1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2],
        [6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12],
    ],
    # S8
    [
        [13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7],
        [1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2],
        [7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8],
        [2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11],
    ]
]
# Straight P-Box Table
SPT = [16, 7, 20, 21, 29, 12, 28, 17,
       1, 15, 23, 26, 5, 18, 31, 10,
       2, 8, 24, 14, 32, 27, 3, 9,
       19, 13, 30, 6, 22, 11, 4, 25]
# Parity Bit Drop Table
PBDT = [57, 49, 41, 33, 25, 17, 9,
        1, 58, 50, 42, 34, 26, 18,
        10, 2, 59, 51, 43, 35, 27,
        19, 11, 3, 60, 52, 44, 36,
        63, 55, 47, 39, 31, 23, 15,
        7, 62, 54, 46, 38, 30, 22,
        14, 6, 61, 53, 45, 37, 29,
        21, 13, 5, 28, 20, 12, 4]
# Compression P-Box Table
CPBT = [14, 17, 11, 24, 1, 5, 3, 28,
        15, 6, 21, 10, 23, 19, 12, 4,
        26, 8, 16, 7, 27, 20, 13, 2,
        41, 52, 31, 37, 47, 55, 30, 40,
        51, 45, 33, 48, 44, 49, 39, 56,
        34, 53, 46, 42, 50, 36, 29, 32]
def plain2bitstring(plain: str):
    return "".join(format(ord(c), "0>8b") for c in plain)
def plain2bitarray(plain: str):
    bitstring = plain2bitstring(plain)
    encoded = bytearray([int(b) for b in bitstring])
    return encoded
def bitarray2plain(bitarray: bytearray):
    bitstring = bitarray2bitstring(bitarray)
    encoded = "".join([chr(int(bitstring[i*8:i*8+8], 2))
                       for i in range(len(bitstring)//8)])
    return encoded
def bitarray2bitstring(bitarray: bytearray):
    return "".join([str(b) for b in bitarray])
def bitarray2bytes(bitarray: bytearray):
    bitstring = bitarray2bitstring(bitarray)
    
    return bytes([int(bitstring[8*i:8*i+8], 2) for i in range(len(bitstring)//8)])
def permutation(block: bytearray, table: list[int], outlen: int):
    permutated = bytearray(outlen)
    for n in range(len(table)):
        m = table[n]-1
        permutated[n] = block[m]
    return permutated
def substitution(block: bytearray, table: list[int]):
    row = (block[0] << 1) + block[5]
    column = (block[1] << 3) + (block[2] << 2) + (block[3] << 1) + block[4]
    val = table[row][column]
    binary = bin(val)[2:].zfill(4)
    return bytearray([int(b) for b in binary])
def key_scheduling(key: bytearray):
    shift_1 = [0, 1, 8, 15]
    round_keys = []
    # Drop parity bit
    parity_erased = permutation(key, PBDT, 56)
    left = parity_erased[:28]
    right = parity_erased[28:]
    # Shift
    for i in range(16):
        if i in shift_1:
            left = left[1:] + left[0:1]
            right = right[1:] + right[0:1]
        else:
            left = left[2:] + left[:2]
            right = right[2:] + right[:2]
        # Compression
        round_keys.append(permutation(left+right, CPBT, 48))
    return round_keys
plain = "DEScrypt"
key = "DreamCry"
# Key scheduling
round_keys = key_scheduling(plain2bitarray(key))
bitarray = plain2bitarray(plain)
# Initial permutation
initial_permutated = permutation(bitarray, IPT, 64)
# Feistel
left_half = initial_permutated[:32]
right_half = initial_permutated[32:]
# Iterate 16 rounds
for round in range(16):
    # Expansion
    expansioned = permutation(right_half, EPT, 48)
    # XOR with round key
    for bit_idx in range(48):
        expansioned[bit_idx] ^= round_keys[round][bit_idx]
    # Substitution
    substituted = bytearray(32)
    for block_idx in range(8):
        substituted[4*block_idx:4*block_idx+4] = substitution(expansioned[6*block_idx:6*block_idx+6], S[block_idx])
    # Straight
    straighted = permutation(substituted, SPT, 32)
    tmp = bytearray(right_half)
    for i in range(32):
        right_half[i] = left_half[i] ^ straighted[i]
    left_half = tmp
# Final permutation
encrypted = permutation(right_half+left_half, FPT, 64)
encrypted = bitarray2bytes(encrypted)
assert(encrypted == DES.new(b"DreamCry", DES.MODE_ECB).encrypt("DEScrypt"))