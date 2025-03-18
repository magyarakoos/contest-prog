for _ in range(int(input())):
    a, b = map(int, input().split())
    ans = 0
    while 1:
        a, b = min(a, b), max(a, b)
        if not a:
            break
        ans += b // a
        b %= a
    print(ans)
