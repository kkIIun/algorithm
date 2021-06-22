def Pow(a,b):
    if b == 0 :
        return 1
    
    if b%2 == 0 :
        return Pow(a, b//2) **2 % mod
    
    else :
        return a*Pow(a,b//2)**2%mod

n, k = map(int, input().split())
mod = 1000000007
A = 1
B = 1

for i in range(n):
    A*= (i+1)
    A %= mod

for i in range(n-k):
    B*= (i+1)
    B%=mod

for i in range(k):
    B*= (i+1)
    B%=mod

print(A*Pow(B,mod-2)%mod)
