#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxn = 1e6 + 5;
int f[maxn];

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    f[0] = 7 % 3, f[1] = 11 % 3;
    for (int i = 2; i <= 1000000; i++) (f[i] = f[i - 1] + f[i - 2]) %= 3;
    int x;
    while (~scanf("%d", &x)) printf("%s\n", (f[x] == 0 ? "yes" : "no"));
    return 0;
}