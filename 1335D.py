n = int(input())

for i in range(n):
    for _ in range(9):
        s = list(input())
        for i in range(9):
            if s[i] == '1' :
                s[i] = '2' 
        print("".join(s))
    
