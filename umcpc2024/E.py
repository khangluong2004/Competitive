n, k = list(map(int, input().split()))

# Check prime
isPrime = True
maxDiv = 1
for i in range(2, n):
    if i * i > n:
        break
    if n % i == 0:
        isPrime = False
        maxDiv = n // i
        break

if not isPrime:
    if k == 1:
        print(1)
    elif k == 2:
        lowBound = maxDiv * (n//maxDiv - 1)
        print(lowBound)
    else:
        print(0)
else:
    if k %2 == 1:
        print(1)
    else:
        print(n - 1)