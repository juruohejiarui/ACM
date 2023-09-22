#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 5;

void solve() {
    int n, m; scanf("%d%d", &n, &m);
    if (n == m) { printf("%d %d\n", n, m); return ; }
    int amx = m, amn = ceil(1.0 * m / (n - m + 1));
    printf("%d %d\n", amx, amn);
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}