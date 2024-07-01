import math

def palindrome(x):
    x = str(x)
    length = len(x)
    test = True
    for i in range(len(x)//2):
        if(x[i]!=x[length-1-i]):
            test = False
            break
    return test

def game():
    count = 0
    while(count<10000000):
        count+=23
        if(palindrome(count)):
            # print(count)
            scount = str(count)
            if(scount[0]==scount[1]):
                if(scount[0] in {'1','3','7','9'}):
                    if(scount[2] in {'1','3','7','9'}):
                        if(scount[0]!=scount[2]):
                            print(scount)

def game2():
    #multiples of 88, try 13-digit and 12-digit
    for i in range(1,10):
        for j in {1,9}:
            for k in range(10):
                for l in {1,9}:
                    for m in range(0,10,2):
                        if(i!=j):
                            if(j!=k):
                                if(k!=l):
                                    if(l!=m):
                                        # num = 10*(10*(10*(10*(10*(10*(10*(10*(10*(i*10+j)+j)+i)+i)+i)+k)+l)+l)+l)+m
                                        # if(num%88==0):
                                        #     print(num)
                                        # num2 = 10*(10*(10*(10*(10*(10*(10*(10*(10*j+j)+i)+i)+i)+k)+l)+l)+l)+m
                                        # if(num2%88==0):
                                        #     print(num2)
                                        continue
        num3 = 10*(10*(10*1+1)+i)+i
        if(num3%88==0):
            print(num3)
        num4 = 10*(10*(10*(10*i+1)+1)+i)+i
        if(num4%88==0):
            print(num4)

def game3():
    #test squares end with 66666
    for i in range(1,10):
        num = 10*(10*(10*(10*(10*(10*i+6)+6)+6)+6)+6)+6
        num2 = 10*(10*(10*(10*(10*i+6)+6)+6)+6)+6
        j=4
        num3 = 10*(10*(10*(10*i+j)+j)+j)+j
        print(math.sqrt(num3))
        # print(math.sqrt(num))
        # print(math.sqrt(num2))
    print(math.sqrt(826281))
    print(math.sqrt(666666))
    print(math.sqrt(66666))
    print(math.sqrt(6666))

def game4():
    for i in range(10):
        for j in range(10):
            num = 10*(10*(10*(10*7+i)+8)+8)+j
            if(num%37==0):
                print(num)

def game5():
    for i in range(10):
        num = 10*(10*(10*(10*(10*4+4)+4)+8)+8)+i
        print(num)
        print(math.sqrt(num))
    print(math.sqrt(44488))
    print(math.sqrt(444))

def game6():
    for i in range(10):
        num = 10*(10*(10*7+i)+8)+8
        if(num%37==0):
            print(num)

def game7():
    for i in range(1,10):
        for j in range(10):
            num = 10*(10*(10*(10*(10*i+i)+i)+8)+8)+j
            # print(num)
            num2 = 10*(10*(10*(10*(10*(10*i+i)+i)+i)+8)+8)+j
            num3 = 10*(10*(10*(10*(10*(10*(10*i+i)+i)+i)+i)+8)+8)+j
            num4 = 10*(10*(10*i+8)+8)+j
            num5 = 10*(10*(10*(10*(10*i+j)+j)+j)+j)+j
            if(math.sqrt(num)%1<0.001):
                print(num)
            # print(math.sqrt(num))

# def june(board):


        


game7()
