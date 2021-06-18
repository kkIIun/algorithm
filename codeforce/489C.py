m, s = map(int,input().split())

if s == 0 and m == 1:
    print(0, 0)
elif s < 1 or m*9 < s:
    print(-1,-1)
else :
    ans = [0]*m
    while s - 9 > 0:
        ans[m-1] = 9
        m -= 1
        s -= 9

    ans[m-1] = s
    Max = map(str,ans[::-1])

    if ans[0] == 0 :
        ans[0] += 1
        for i in range(1,len(ans)):
            if ans[i] != 0 :
                ans[i] -= 1
                break;
    Min = map(str,ans[:])
    print("".join(Min), "".join(Max))