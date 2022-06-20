def getfromradix251(arr):
    x = 0
    for val in arr[::-1]:
        x <<= 51
        x ^= val
    print(f"[ i ] Number representation: {hex(x)}")
    return x

print('[ i ] Enter 5 hex 2^51-digits: ')
arr = []
for _ in range(5):
    arr.append(int(input(), 16))
getfromradix251(arr)