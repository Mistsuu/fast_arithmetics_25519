from random import randrange

def getfromradix247(arr):
    x = 0
    for val in arr[::-1]:
        x <<= 47
        x ^= val
    print(f"[ i ] Number representation: {hex(x)}")
    return x

def splitradix247(x):
    arr = []
    for _ in range(2):
        arr.append(x & 0x7fffffffffff)
        x >>= 47
    arr.append(x & 0xffffffffffff)

    print("[ i ] Radix representation: [")
    for val in arr:
        print(f"   {hex(val)}")
    print("]")
    return arr

getfromradix247(splitradix247(randrange(0, 2**142-111)))