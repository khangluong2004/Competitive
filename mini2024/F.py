# TLE

t = int(input())

for z in range(t):
    n = int(input())
    values = list(map(int, input().split()))
    removable = [True] * n

    # print(removable)
    seen = set()
    for i in range(n-1, -1, -1):
        if values[i] not in seen:
            removable[i] = False
        seen.add(values[i])

    result = []
    dist = list(seen)
    dist.sort(key=lambda x: -x)

    i = 0

    removing = False
    maxSoFar = None
    maxPosition = -1
    leastSoFar = None
    leastPosition = -1
    seen = set()

    while i < len(values):
        # print(i, values[i])
        # print(maxSoFar)
        # print(leastSoFar)
        # print(result)
        # print()
        # print(maxSoFar, values[i])
        if (values[i] in seen):
            i += 1
            continue

        # Find unremovable items
        if not removing:
            if removable[i] == False:
                result.append(values[i])
                seen.add(values[i])
                i += 1
                continue

            # Remove removable
            removing = True
            maxSoFar = values[i]
            leastSoFar = values[i]
            maxPosition = i
            leastPosition = i
            i += 1
            continue
        # If removing
        else:
            # Find unremovable, stop removing
            if removable[i] == False:
                if len(result) % 2 == 0:
                    if values[i] > maxSoFar:
                        result.append(values[i])
                        seen.add(values[i])
                    else:
                        result.append(maxSoFar)
                        seen.add(maxSoFar)

                        removing = False
                        maxSoFar = None
                        i = maxPosition + 1

                        continue
                else:
                    if values[i] < leastSoFar:
                        result.append(values[i])
                        seen.add(values[i])
                    else:
                        result.append(leastSoFar)
                        seen.add(leastSoFar)

                        removing = False
                        leastSoFar = None
                        i = leastPosition + 1

                        continue
                i += 1
                removing = False
                maxSoFar = None
                continue
            else:
                if values[i] > maxSoFar:
                    maxSoFar = values[i]
                    maxPosition = i
                if values[i] < leastSoFar:
                    leastSoFar = values[i]
                    leastPosition = i
                i += 1
                continue

    print(len(result))
    print(' '.join([str(value) for value in result]))

                




