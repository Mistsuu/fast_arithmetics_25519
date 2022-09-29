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

number = int(input('[ i ] Enter a hex number: '), 16)
splitradix248(number)