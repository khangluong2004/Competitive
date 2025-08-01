n = int(input())
allPairs = []

for i in range(n):
    x, y = list(map(int, input().split()))
    allPairs.append((x, y))


allPairs.sort(key = lambda x: x[0])

