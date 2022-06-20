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

number = int(input('[ i ] Enter a hex number: '), 16)
splitradix251(number)