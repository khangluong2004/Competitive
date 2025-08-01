n = int(input())
str1 = input()
str2 = input()

yes = False
for i in range(n):
    flag = 0
    for j in range(n):
        if str1[j] != str2[(i + j) % n]:
            flag = 1
            break
    if flag == 0:
        print("Yes")
        yes = True
        break

if not yes:
    print("No")