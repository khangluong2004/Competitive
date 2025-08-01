t = int(input())

for z in range(t):
    n = int(input())

    ans = "YES"
    strHalf = str(n)

    if strHalf[-1] == '9':
        print("NO")
        continue

    firstDigit = int(strHalf[0])
    if firstDigit != 1:
        print("NO")
        continue


    for charac in strHalf[1:-1]:
        digit = int(charac)
        if digit == 0:
            ans = "NO"
            break

    

    print(ans)
            