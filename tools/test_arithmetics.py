from pwn import process
import os

# Compile binary
os.chdir('..')
os.system('make main')

def queryValues():
    io = process(['./main'])
    
