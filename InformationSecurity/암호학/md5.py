import hashlib
print(hashlib.md5(b'dreamhack').hexdigest()) # str, 298d75fe864c08e3a68dd1da1483654d
print(hashlib.md5(b'dreamhacc').hexdigest()) # str, 02ac31c7f653161b28554a383ba36bae
# MD5 hash of file 
with open('/path/to/file', 'rb') as f:
    print(hashlib.md5(f.read()).hexdigest())