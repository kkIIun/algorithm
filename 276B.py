s = list(input())
dict = {}

for i in range(len(s)):
    if s[i] in dict:
        dict[s[i]] += 1
    else:
        dict[s[i]] = 1

for i in range(len(s), 0, -1):
    odd = 0
    for key, value in dict.items():
        if value % 2 != 0:
            char = key
            odd += 1
    if (i % 2 == 0 and odd == 0) or (i % 2 != 0 and odd == 1):
        print("First" if (len(s) - i) % 2 == 0 else "Second")
        break
    dict[char] -= 1
