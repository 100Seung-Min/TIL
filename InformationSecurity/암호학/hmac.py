#!/usr/bin/env python3
# Name: hmac.py
import hashlib, hmac
# key : b'secret', msg : b'hello world'
h = hmac.new(b'secret', b'hello world', hashlib.sha256).hexdigest() 
print(h) # 734cc62f32841568f45715aeb9f4d7891324e6d948e4c6c60c0621cdac48623a