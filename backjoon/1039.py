from collections import deque
import sys

n, k = input().split()
q = deque()
q.append(n)
Max = 0

for l in range(int(k)):
    lq = len(q)
    for _ in range(lq):
        val = list(q.popleft())
        for i in range(len(val)):
            for j in range(i + 1, len(val)):
                temp = val[:]
                temp[i], temp[j] = temp[j], temp[i]
                if temp[0] == '0':
                    continue
                num = int("".join(temp))
                q.append(str(num))
                if l == int(k) - 1:
                    Max = max(Max, num)
    q = deque(list(set(q)))

print(Max if Max != 0 else -1)
