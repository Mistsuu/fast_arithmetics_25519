from random import randrange

def getfromradix248(arr):
    x = 0
    for val in arr[::-1]:
        x <<= 48
        x ^= val
    print(f"[ i ] Number representation: {hex(x)}")
    return x

def splitradix248(x):
    arr = []
    for _ in range(3):
        arr.append(x & 0xffffffffffff)
        x >>= 48

    print("[ i ] Radix representation: [")
    for val in arr:
        print(f"   {hex(val)}")
    print("]")
    return arr

getfromradix248(splitradix248(randrange(0, 2**142-111)))