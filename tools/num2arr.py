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

number = int(input('[ i ] Enter a hex number: '), 16)
splitradix247(number)