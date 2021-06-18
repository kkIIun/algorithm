n = int(input())
dict = {}
for _ in range(n):
    word = str(input())
    if word in dict:
        dict[word] += 1
        print("{0}{1}".format(word, dict[word]))
    else:
        dict[word] = 0
        print("OK")