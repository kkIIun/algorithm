n = input()
array = [int(x) for x in input().split()]

Carray = array[:]
Carray.sort()
first, seccond, fleg = 0, 0, 0
for i in range(len(array) - 1):
    if array[i] > array[i + 1] and fleg == 0:
        first = i
        fleg = 1

    elif array[first] < array[i + 1] and fleg == 1:
        seccond = i
        fleg += 1

if fleg and seccond == 0:
    seccond = len(array) - 1
array = array[:first] + array[first : seccond + 1][::-1] + array[seccond + 1 :]

if Carray != array:
    print("no")

else:
    print("yes")
    print(first + 1, seccond + 1)
