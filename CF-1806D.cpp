#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 5e5 + 5;
const LL MOD = 998244353;

int n, a[maxn];
LL f[maxn], ans[maxn];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) scanf("%d", &a[i]);
    f[1] = 1;
    for (int i = 1; i < n; i++) f[i + 1] = f[i] * (i - a[i]) % MOD;
    for (int i = 1; i < n; i++) ans[i] = (ans[i - 1] * i % MOD + (1 - a[i]) * f[i]) % MOD;
    for (int i = 1; i < n; i++) printf("%lld ", ans[i]);
    putchar('\n');
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}