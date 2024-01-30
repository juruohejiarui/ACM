#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
int n, m, mxa, ans[maxn];
inline int id(int x, int y) { return x * m + y; }

void solve() {
    scanf("%d%d", &n, &m);
    if (m == 1) { 
        mxa = 0;
        for (int i = 0; i < n; i++) ans[id(i, 0)] = 0;
    } else if (n >= m) {
        mxa = m;
        for (int i = 0; i < m - 1; i++)
            for (int j = 0; j < m; j++)
                ans[id(i, j)] = (i + j + 1) % m;
        for (int i = m - 1; i < n; i++)
            for (int j = 0; j < m; j++) ans[id(i, j)] = (j + 1) % m;
    } else {
        mxa = n + 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans[id(i, j)] = (i + j + 1) % m;
    }
    printf("%d\n", mxa);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", ans[id(i, j)]);
        putchar('\n');
    }
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}