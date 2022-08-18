
def main():
    num1 = 3141592653589793238462643383279502884197169399375105820974944592
    num2 = 2718281828459045235360287471352662497757247093699959574966967627
    result = karatsuba(num1, num2)
    print(result)

def karatsuba(num1, num2):
    num1Str = str(num1)
    num2Str = str(num2)
    if (num1 < 10) or (num2 < 10):
        return num1*num2

    maxLength = max(len(num1Str), len(num2Str))
    splitPosition = maxLength // 2
    high1, low1= int(num1Str[:-splitPosition]), int(num1Str[-splitPosition:])
    high2, low2= int(num2Str[:-splitPosition]), int(num2Str[-splitPosition:])
    z0 = karatsuba(low1, low2)
    z1 = karatsuba((low1 + high1), (low2 + high2))
    z2 = karatsuba(high1, high2)

    return (z2*10**(2*splitPosition)) + ((z1-z2-z0)*10**(splitPosition))+z0


main()