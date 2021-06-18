n = int(input())

a = [int(x) for x in input().split()]

stack = []
ans = 0

for i in range(len(a)):
    if not stack and a[i] != 0:
        stack.append(a[i])

    elif a[i] == 0:
        ans += 1
        stack.append(a[i])

    elif a[i] == 1:
        if stack[-1] == 1:
            ans += 1
            stack.append(0)
        else:
            stack.append(a[i])

    elif a[i] == 2:
        if stack[-1] == 2:
            ans += 1
            stack.append(0)
        else:
            stack.append(a[i])

    elif a[i] == 3:
        if stack[-1] == 1:
            stack[-1] += 1
        elif stack[-1] == 2:
            stack[-1] -= 1

print(ans)