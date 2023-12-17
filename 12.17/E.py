def solve():
    n = int(input())
    a = list(map(int, input().split(' ')))
    col = input()
    rls, bls = [], []
    for i in range(0, n):
        if col[i] == 'R':
            rls.append(a[i])
        else:
            bls.append(a[i])
    rls.sort()
    bls.sort()
    for i in range(0, len(bls)):
        if bls[i] <= i:
            print("NO")
            return
    for i in range(0, len(rls)):
        if rls[i] > n - (len(rls) - i - 1):
            print("NO")
            return
    print("YES")


if __name__ == "__main__":
    T = int(input())
    while T > 0:
        solve()
        T -= 1
