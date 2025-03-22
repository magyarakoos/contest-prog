A = []
def read():
N = int(input())
for _ in range(N):
    x, y = map(int, input().split())
    A.append(complex(x, y))
