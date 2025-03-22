def read():
    n = int(input())
    a = []
    for _ in range(n):
        x, y = map(int, input().split())
        a.append(complex(x, y))
    return a

def hull(ptS):
    pass

A, B = read(), read()
print("YES" if hull(A + B) == hull(A) else "NO")
