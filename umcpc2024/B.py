n = int(input())
vals = list(map(int, input().split()))

vals.sort(key = lambda x: -x)

# print(vals)
freq = {}

distinct = []

for i in range(0, n):
    if vals[i] not in freq:
        freq[vals[i]] = 1
        distinct.append(vals[i])
    else:
        freq[vals[i]] += 1

count = freq[distinct[0]]
for i in range(1, len(distinct)):
    if freq[distinct[i]] > count:
        count = freq[distinct[i]] 

        
# print(groups)
# print(outers)

print(count)