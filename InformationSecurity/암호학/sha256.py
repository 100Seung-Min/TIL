#!/usr/bin/env python3
# Name: sha256.py
import hashlib
print(hashlib.sha256(b'theori').hexdigest()) # str, 95610a88dd5e9cd53a1ba879608d8cbd938f8dea4ea800dcc7c4d925a4466e47
print(hashlib.sha256(b'theorr').hexdigest()) # str, acd88112d4c87351e193cfd425cf7f01925ea15b9c03b7be03ad1343c8f13f70
# SHA256 hash of file 
with open('/path/to/file', 'rb') as f:
    print(hashlib.sha256(f.read()).hexdigest())