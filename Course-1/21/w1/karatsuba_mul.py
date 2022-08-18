import sys


def main():
    try:
        x = int(input('Enter a number: '))
        y = int(input('Enter another: '))
    except:
        print("must provide integers")

    result = karatsuba(x, y)
    print(result, x*y)
    print(round(3.5))

def karatsuba(x, y):

    if x < 10 or y < 10:
        return x * y

    n = max(len(str(x)), len(str(y)))
    half = n // 2

    a, b, c, d = separator(x, y)
    ac = karatsuba(a, c)
    bd = karatsuba(b, d)
    apb_cpd = karatsuba(a+b, c+d)
    ad_bc = apb_cpd - ac- bd
    return 10**(half*2)*ac + 10**half*ad_bc + bd

def separator(x, y):
    lx = round(len(str(x)) / 2)
    ly = round(len(str(y)) / 2)

    a = int(str(x)[:lx])
    b = int(str(x)[lx:])
    c = int(str(y)[:ly])
    d = int(str(y)[ly:])
    return a, b, c, d


main()
