def solve():
    n = int(input())
    ls = list(map(int, input().split()))
    y2 = int(input())
    for i in range(1, ls[0] + 1):
        if ls[i] > y2:
            print(f"{y2 - n + 1 - (i - 1)}")
            return 
    print(f"{y2 - n + 1 - ls[0]}")
if __name__ == "__main__":
    T = int(input())
    while T > 0:
        solve()
        T -= 1