def getfromradix248(arr, debug=False):
    x = 0
    for val in arr[::-1]:
        x <<= 48
        x ^= val

    if debug:
        print(f"[ i ] Number representation: {hex(x)}")
        
    return x

if __name__ == '__main__':
    print('[ i ] Enter 3 hex 2^48-digits: ')
    arr = []
    for _ in range(3):
        arr.append(int(input(), 16))
        getfromradix248(arr, debug=True)