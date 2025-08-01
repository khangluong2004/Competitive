
line = input().split()
swaps = int(input())

for i in range(swaps):
    pair = input().split()
    first = int(pair[0]) - 1
    second = int(pair[1]) - 1
    temp = line[first]
    line[first] = line[second]
    line[second] = temp

print(" ".join(line))
