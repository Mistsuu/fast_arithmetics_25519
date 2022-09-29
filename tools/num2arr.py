def splitradix248(x, debug=False):
    arr = []
    for _ in range(3):
        arr.append(x & 0xffffffffffff)
        x >>= 48

    if debug:
        print("[ i ] Radix representation: [")
        for val in arr:
            print(f"   {hex(val)}")
        print("]")

    return arr

if __name__ == '__main__':
    number = int(input('[ i ] Enter a hex number: '), 16)
    splitradix248(number, debug=True)