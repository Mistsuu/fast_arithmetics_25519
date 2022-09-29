import os
from pwn import process, context

# Remove log from pwntools
context.log_level = 'error'

# Compile binary
os.chdir('..')
os.system('make main > /dev/null')

p = 2**142 - 111
def testMultiplication():
    io = process(['./main'])
    
    x = int(io.readline().decode().strip(), 16)
    y = int(io.readline().decode().strip(), 16)
    z = int(io.readline().decode().strip(), 16)
    
    io.close()
    
    print(f'{hex(x)[2:].zfill(36)} * {hex(y)[2:].zfill(36)} = {hex(z)[2:].zfill(36)} => {x * y % p == z}')

for _ in range(20):
    testMultiplication()