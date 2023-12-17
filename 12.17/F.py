if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split(' ')))
    a.sort()
    sx, sy = 0, 0
    for i in range(n // 2):
        sx += a[i]
    for i in range(n // 2, n):
        sy += a[i]
    print(sx ** 2 + sy ** 2)