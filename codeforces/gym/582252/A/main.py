for _ in range(int(input())):
    a, b = map(int, input().split())
    ans = 0
    while a > 0:
        a, b = min(a, b), max(a, b)
