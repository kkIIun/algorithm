import math


def calc(n, i):
    num1, num2 = 1, 1

    for j in range(i):
        num1 *= n - j
        num2 *= j + 1
    return num1 / num2


str1 = input()
str2 = input()

value1, value2, cnt = 0, 0, 0
prob = {}

for char in str1:
    if char == "+":
        value1 += 1
    elif char == "-":
        value1 -= 1

for char in str2:
    if char == "+":
        value2 += 1
    elif char == "-":
        value2 -= 1
    elif char == "?":
        cnt += 1

value = value1 - value2

for i in range(len(str1) // 2 + 1):
    prob[(cnt - i) * -1 + i] = calc(cnt, i)
    prob[((cnt - i) * -1 + i) * -1] = calc(cnt, i)

if cnt == 0 and value == 0:
    print(1.0)
elif cnt == 0 and value != 0:
    print(0.0)
else:
    if value in prob:
        print(prob[value] / math.pow(2, cnt))
    else:
        print(0.0)
