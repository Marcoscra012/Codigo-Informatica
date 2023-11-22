#BASE64

import base64
import random

ini_pass = input("Introduce a password: ")
a = ini_pass.encode("ascii")
final_pass = base64.b64encode(a)

#NO BASE64
n = 0
chars = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890!"·$%&/()='
final_message = ""

for i in ini_pass:
    final_message += chars[n+32]
    n+=1

print(f"Base64: {final_pass} \nNo Base64: {final_message}")