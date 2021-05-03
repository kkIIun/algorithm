n, m = map(int,input().split())

click = 0
stack = []
visited = [False] * 10000
stack.append(n)
while m not in stack :    
    pop = []
    while stack :
        pop.append(stack.pop())
    
    for i in range(len(pop)):
        if pop[i] <= 0 :
            pass
        elif pop[i] > m  :
            stack.append(pop[i]-1)
            visited[pop[i]-1] = True
        else :
            if visited[pop[i]-1] == False :
                stack.append(pop[i]-1)
                visited[pop[i]-1] = True

            if visited[pop[i]*2] == False :
                stack.append(pop[i]*2)
                visited[pop[i]*2] = True
    
    click += 1

print(click)