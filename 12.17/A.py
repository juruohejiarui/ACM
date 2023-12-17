def solve() :
    n, m = map(int, input().split(' '))
    a = list(map(int, input().split(' ')))
    if m >= 2: 
        print("YES")
        return 
    for i in range(1, n) :
        if a[i - 1] > a[i]:
            print("NO")
            return
    print("YES")
if __name__ == "__main__":
    T = int(input())
    while T > 0:
        T -= 1
        solve()