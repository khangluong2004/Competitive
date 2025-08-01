t = int(input())

for z in range(t):
    count = {}
    n = int(input())
    values = list(map(int, input().split()))

    maxi = -1
    for value in values:
        if value not in count:
            count[value] = 0
        count[value] += 1
        maxi = max(count[value], maxi)
    
    print(n - maxi)
