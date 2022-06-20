from random import randrange

def getfromradix251(arr):
    x = 0
    for val in arr[::-1]:
        x <<= 51
        x ^= val
    print(f"[ i ] Number representation: {hex(x)}")
    return x

def splitradix251(x):
    arr = []
    while x:
        arr.append(x & 0x7ffffffffffff)
        x >>= 51

    print("[ i ] Radix representation: [")
    for val in arr:
        print(f"   {hex(val)}")
    print("]")
    return arr

getfromradix251(splitradix251(randrange(0, 2**255-19)))