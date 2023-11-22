#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    scanf("%d%d", &a, &b);
    int ans = a + b;
    for (int i = 2; i <= 300000; i++) ans = min(ans, (a + i - 1) / i + (b + i - 1) / i + (i - 1));
    printf("%d\n", ans);
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}