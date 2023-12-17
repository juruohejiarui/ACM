def solve():
    n = int(input())
    a = list(map(int, input().split(' ')))
    a.insert(0, 0)
    pw2 = 1
    while pw2 < n:
        npw2 = pw2 << 1
        for i in range(pw2 + 2, min(npw2, n) + 1):
            if a[i - 1] > a[i]:
                print("NO")
                return 
        pw2 = npw2
    print("YES")

if __name__ == "__main__":
    T = int(input())
    while T > 0:
        solve()
        T -= 1