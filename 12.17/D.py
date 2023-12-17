def solve():
    n = int(input())
    a = list(map(int, input().split(' ')))
    a.sort()
    p, c = 0, n - 1
    while p < n * (n - 1) // 2:
        print(a[p], end = ' ')
        p += c
        c -= 1
    print('1000000000')

if __name__ == "__main__":
    T = int(input())
    while T > 0:
        solve()
        T -= 1