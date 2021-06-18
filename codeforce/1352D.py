t = int(input())

for _ in range(t):
    n = input()
    arr = [int(x) for x in input().split()]

    left, right, move, candle = 0, 0, 1, 0
    while arr:
        Sum = 0
        if move % 2 == 0:
            while Sum < candle + 1 and arr:
                pop = arr.pop()
                Sum += pop
                right += pop
        else:
            while Sum < candle + 1 and arr:
                pop = arr.pop(0)
                Sum += pop
                left += pop
        candle = Sum
        move += 1
    print(move - 1, left, right)
