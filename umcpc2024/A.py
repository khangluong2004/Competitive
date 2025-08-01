def subtractDict(freqStr, strDict, mult):
    for char in strDict:
        if char not in freqStr:
            return -1
    
    for char in strDict:
        freqStr[char] -= mult * strDict[char]
    return 1

def getAvail(freqStr, strDict):
    count = n
    for char in strDict:
        if char not in freqStr:
            return 0

        count = min(count, freqStr[char] // strDict[char])
    return count % n
    


n = int(input())
inputStr = input()

str1 = "shikanokonokonokoshitantan"
str2 = "brrskibididopdopyesyesshtibididipdipww"

dict1 = {'s': 2, 'h': 2, 'i': 2, 'k': 4, 'a': 3, 'n': 5, 'o': 6, 't': 2}
dict2 = {'b': 3, 'r': 2, 's': 4, 'k': 1, 'i': 8, 'd': 6, 'o': 2, 'p': 4, 'y': 2, 'e': 2, 'h': 1, 't': 1, 'w': 2}

freqStr = {}

for char in inputStr:
    if char not in freqStr:
        freqStr[char] = 0
    freqStr[char] += 1


count1 = getAvail(freqStr, dict1)

count2 = getAvail(freqStr, dict2)


if count2 == 0:
    print(count1)
elif count1 == 0:
    print(count2)
elif count2 <= count1:
    maxNum = -1
    for i in range(0, count2 + 1):
        copyFreqStr = freqStr.copy()
        subtractDict(copyFreqStr, dict2, i)
        count1 = getAvail(copyFreqStr, dict1)
        if maxNum == -1:
            maxNum = count1 + i
        else:
            maxNum = max(maxNum, count1 + i)
    print(maxNum)
else:
    maxNum = -1
    for i in range(0, count1 + 1):
        copyFreqStr = freqStr.copy()
        subtractDict(copyFreqStr, dict1, i)
        count2 = getAvail(copyFreqStr, dict2)
        if maxNum == -1:
            maxNum = count2 + i
        else:
            maxNum = max(maxNum, count2 + i)
    print(maxNum)
        













# for char in str1:
#     if char not in dict1:
#         dict1[char] = 0
#     dict1[char] += 1

# for char in str2:
#     if char not in dict2:
#         dict2[char] = 0
#     dict2[char] += 1


# count = n
# for char in dict1:
#     if char not in freqStr:
#         count = 0
#         break
#     count = min(count, freqStr[char] // dict1[char])

# if count == n:
#     count = 0

# if count != 0:
#     for char in dict1:
#         freqStr[char] -= dict1[char] * count

# count2 = n
# for char in dict2:
#     if char not in freqStr:
#         count2 = 0
#         break
#     count2 = min(count2, freqStr[char] // dict2[char])

# if count2 == n:
#     count2 = 0

# print(count + count2)
    
