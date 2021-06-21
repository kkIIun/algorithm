import heapq,sys

maxheap = []
minheap = []
ans = []

n = int(sys.stdin.readline())
for i in range(n):

    In = int(sys.stdin.readline())

    if len(maxheap) == len(minheap):
        heapq.heappush(maxheap, (-In,In))

    else :
        heapq.heappush(minheap, (In,In))

    if minheap and minheap[0][1] < maxheap[0][1] :
        mintemp = heapq.heappop(minheap)[1]
        maxtemp = heapq.heappop(maxheap)[1]
        heapq.heappush(maxheap, (-mintemp,mintemp))
        heapq.heappush(minheap, (maxtemp,maxtemp))
    
    print(maxheap[0][1])
