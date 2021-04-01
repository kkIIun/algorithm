n = input()
array = [int(x) for x in input().split()]

Carray = array[:]
Carray.sort()
first, seccond, fleg = 1, 1, 0
for i in range(len(array) - 1):
    if array[i] > array[i + 1]:
        first = i
    elif array[first] < array[i + 1] and fleg == 0:
        seccond = i
        fleg = 1

i = 0
for item in array[1:-1:-1]:
    array[i] = item
    i += 1
    print(item)

print(array)
if Carray != array:
    print("no")

else:
    print("yes")
    print(first, seccond)
