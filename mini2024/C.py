def getSum(n, x):
    sums = 0
    for i in range(1, n + 1):
        if x * i > n:
            break
        sums += i * x
    return sums

t = int(input())

for z in range(t):
    n = int(input())
    maxSum = -1
    maxElem = -1

    for i in range(2, n + 1):
        curSum = getSum(n, i)
        if curSum > maxSum:
            maxSum = curSum
            maxElem = i
    print(maxElem)