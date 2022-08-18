import sys


def main():
    x = input('Enter a number: ')
    y = input('Enter another: ')

    result = karatsuba(x, y)
    print(result)
    sys.exit(0)

def karatsuba(x, y):

    a, b, c, d = separator(x, y)

def separator(x, y):
    l1 = len(str(x))
    l2 = len(str(y))
    # a = int(str(x)[:int(l1/2]))
    # b = int(str(x)[l1/2:])
    # c = int(str(x)[:l2/2])
    # d = int(str(x)[l2/2:])
    
    for ch in str(x):
        if i < l1:
            a += 
    return a, b, c, d


main()