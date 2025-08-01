import math

def findMin(n):
    if n == 1:
        return 1
    if n == 2:
        return 2
    
    l = 1
    r = n

    mini = 1000000000
    
    while l <= r:
        print(l, r)
        m = l + (r - l)//2
        left = m
        right = findMin(n - m) + 1

        if left <= right:
            l = m + 1
        elif left > right:
            r = m - 1
        mini = min(max(left, right), mini)
    
    return mini


# def findMinOther(n):
#     maxi = -1
#     start = 1
#     cur = 0
#     while start < n:
#         curVal = cur + 1 + (start - 1)
#         cur += 1
#         start *= 2
#         maxi = max(maxi, curVal)
#     return maxi
        

n = int(input())
print(findMin(n))


