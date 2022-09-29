import os
from pwn import process, context
from tqdm import trange

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
    r = int(io.readline().decode().strip(), 16)
    w = int(io.readline().decode().strip(), 16)
    z = int(io.readline().decode().strip(), 16)
    
    io.close()
    
    return (x + y + r + 5*w)**2 % p == z

count = 0
total = 2000
for _ in trange(total):
    count += int(testMultiplication())
print(f"Accuracy: {count}/{total} => {count/total*100}%")