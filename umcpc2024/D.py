n = int(input())

eps = 0.000001
matrix = [[0] * n for i in range(n)]

maxDist = -1
maxPoints = (0, 0)
for i in range(n):
    line = list(map(int, input().split()))
    for j in range(n):
        matrix[i][j] = line[j]

        if matrix[i][j] > maxDist:
            maxDist = matrix[i][j]
            maxPoints = (i, j)

distance = maxDist * 1.0 / 2

# Check if possible
possible = True
for i in range(n):
    if i == maxPoints[0] or i == maxPoints[1]:
        continue

    if not (matrix[maxPoints[0]][i] == maxDist 
        or matrix[maxPoints[1]][i] == maxDist):
        possible = False
        break

if possible:
    print(round(distance))
else:
    print(-1)

    

