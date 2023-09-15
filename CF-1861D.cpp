#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int n, a[maxn], f1[maxn], f2[maxn];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    f1[1] = f2[n] = 0;
    for (int i = 2; i <= n; i++)
        f1[i] = f1[i - 1] + (a[i] >= a[i - 1]);
    for (int i = n - 1; i >= 1; i--)
        f2[i] = f2[i + 1] + (a[i] >= a[i + 1]);
    int ans = min(f1[n] + 1, f2[1]);
    for (int i = 2; i <= n; i++)
        ans = min(ans, f1[i - 1] + 1 + f2[i]);
    printf("%d\n", ans);
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}