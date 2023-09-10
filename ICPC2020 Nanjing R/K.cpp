#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 1e6 + 5;

int ans[maxn];

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n, k; scanf("%d%d", &n, &k);
    for (int i = 1; i < k; i++) ans[i] = i + 1;
    ans[k] = 1;
    if (k == 0) { printf("-1\n"); return 0; }
    for (int i = k + 1; i <= n; i++) ans[i] = i;
    for (int i = 1; i <= n; i++) {
        printf("%d", ans[i]);
        if (i < n) putchar(' ');
    }
    return 0;
}