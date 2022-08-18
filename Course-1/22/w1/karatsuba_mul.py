"""
            Karatsuba Multiplication
    x and y two n-digits number
    x = 10^(n/2)a + b
    y = 10^(n/2)c + d
    x.y = 10^n.ac + 10^2(ad+bc) + bd
    1- ac
    2- bd
    3- (a+b)(c+d)
    4- 3-2-1 = ad+bc

    I'm using python to hold bih numbers
"""

def main():
    # try:
    #     x = int(input("Enter a positive value: "))
    #     y = int(input("Enter a positive value: "))
    # except:
    #     print("must provide integers")
    # x = 1234
    # y = 5678
    # x = 1234 # a + b
    # y = 5678 # c + d
    x = 3141592653589793238462643383279502884197169399375105820974944592
    y = 2718281828459045235360287471352662497757247093699959574966967627

    # print(len(str(x)), len(str(y)))

    result = karatsuba(x,y)
    # print(result)
    # the correct answer is:
    # 8539734222673567065463550869546574495034888535765114961879601127067743044893204848617875072216249073013374895871952806582723184
    # So, something wrog with mine
    print(f"karatsuba : {result} \n--- x.y = {x*y}")

    return 0


def karatsuba(x, y):
    # base case
    if x < 10 or y < 10:
        return x * y
    # if len(str(x)) == 2 and len(str(y)) == 3:
    
    # Devide x to a and b, and y to c and d
    a, b, c, d = separator(x, y)
    
    # Algorithm 4 steps
    ac = karatsuba(a, c)
    bd = karatsuba(b, d)
    gauss = karatsuba(a + b, c + d)
    ad_p_bc = gauss - ac - bd
    # ad = karatsuba(a, d)
    # bc = karatsuba(b, c)
    # ad_p_bc = ad + bc
    max = x if x > y else y
    n = len(str(max))
    half = n // 2

    result = 10**(half*2)*ac + 10**half*ad_p_bc + bd
    # result = 10**n*ac + 10**(n//2)*(ad+bc) + bd
    # result = 10**n*ac + 10**(n//2)*ad + 10**(n//2+1)*bc + bd
    return result

def separator(x, y):
    xsplit = round(len(str(x))/2)
    ysplit = round(len(str(y))/2)
    
    a = int(str(x)[:xsplit])
    b = int(str(x)[xsplit:])
    c = int(str(y)[:ysplit])
    d = int(str(y)[ysplit:])

    return a, b, c, d

main()