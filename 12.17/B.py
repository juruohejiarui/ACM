import math
def solve():
    n = int(input())
    a = list(map(int, input().split(' ')))
    a.sort()
    ans = a[(n << 1) - 1] - a[n] + a[n - 1] - a[0]
    print(ans)
    for i in range(0, n):
        print(f"{a[i]} {a[i + n]}")

if __name__ == "__main__":
    T = int(input())
    while T > 0:
        solve()
        T -= 1