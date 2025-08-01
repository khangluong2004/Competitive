t = int(input())

for z in range(t):
    n, k = list(map(int, input().split()))
    values = list(map(int, input().split()))
    values.sort(key=lambda x: -x)
    possible = k

    for i in range(1, len(values), 2):
        if possible == 0:
            break
        change = values[i-1] - values[i]
        if possible < change:
            values[i] += possible
            possible = 0
        else:
            values[i] += change
            possible -= change
    
    sum2 = 0
    for i in range(1, len(values), 2):
        sum2 += values[i]

    sum1 = sum(values) - sum2
    print(sum1 - sum2)
