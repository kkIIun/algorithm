n = input()
arr = [int(x) for x in input().split()]

arr.sort()
Sum, cnt = arr[0], 1
for i in range(1, len(arr)):
    if Sum <= arr[i]:
        cnt += 1
        Sum += arr[i]

print(cnt)