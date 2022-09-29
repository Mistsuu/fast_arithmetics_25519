def getfromradix248(arr):
    x = 0
    for val in arr[::-1]:
        x <<= 48
        x ^= val
    print(f"[ i ] Number representation: {hex(x)}")
    return x

print('[ i ] Enter 3 hex 2^48-digits: ')
arr = []
for _ in range(3):
    arr.append(int(input(), 16))
getfromradix248(arr)