l_int = list(map(int, input().split()))
g = l_int[0]
words = l_int[1]

allowed = [set() for i in range(5)]

for j in range(5):
    allowed[j] = set("ABCDEFGHIJKLMNOPQRSTUVWXYZ")    

for _ in range(g):
    guess, hint = tuple(input().split())
    green = set()
    yellow = set()
    for i in range(len(hint)):
        if hint[i] == "G":
            green.add(guess[i])
        
    
    for i in range(len(hint)):
        char = hint[i]
        if char == "-":
            if guess[i] in yellow or guess[i] in green:
                if guess[i] in allowed[i]:
                    allowed[i].remove(guess[i])
            else:
                for j in range(5):
                    if guess[i] in allowed[j]:
                        allowed[j].remove(guess[i])
        elif char == "G":
            allowed[i] = set([guess[i]])
        else:
            if guess[i] in allowed[i]:
                allowed[i].remove(guess[i])
        # if _ == 1:
        #     print(yellow)
#     print('T' in allowed[0])

# for thing in allowed:
#     print(thing)

for _ in range(words):
    word = input()
    valid  = True
    for i in range(len(word)):
        if word[i] not in allowed[i]:
            valid = False
            break
    if valid:
        print(word)
