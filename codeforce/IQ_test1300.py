n = input().split()
index = [int(x) for x in input().split()]

if index[0] % 2 != index[1] % 2:
    if index[0] % 2 == index[2] % 2:
        print(2)
    else:
        print(1)

else:
    std = index[0] % 2
    for i in range(1, len(index)):
        if index[i] % 2 != std:
            print(i + 1)
            break
