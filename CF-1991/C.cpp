#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x, y, ans = 0;
    scanf("%d", &n), x = y = n + 5;
    for (int i = 1; i <= n; i++) {
        int ai; scanf("%d", &ai);
        if (y < ai) x = y, y = ai, ans++;
        else if (x < ai) y = ai;
        else x = ai;
    }
    printf("%d\n", ans);
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}