#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL MOD = 998244353;
const int maxn = 2e5 + 5;

LL fac[maxn], ifac[maxn], inv[maxn];

void init(int n) {
    fac[0] = ifac[0] = inv[1] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
    for (int i = 2; i <= n; i++) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    for (int i = 1; i <= n; i++) ifac[i] = ifac[i - 1] * inv[i] % MOD;
}

inline LL C(int n, int m) { return fac[n] * ifac[m] % MOD * ifac[n - m] % MOD; }

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n, m, x, y; LL ans = 0;
    scanf("%d%d%d%d", &m, &n, &x, &y);
    init(max(n, m) << 1);
    if (y <= n)
        for (int i = 1; i <= m; i++)
            (ans += C(i + (x - 1) - 1, x - 1) * C((m - i + 1) + n - y - 1, n - y) % MOD * C(m + n - 1, n) % MOD) %= MOD;
    else if (x > n)
        for (int i = 1; i <= m; i++) 
            (ans += C(m + n - 1, n) * C((m - i + 1) + (x - n - 1) - 1, x - n - 1) % MOD * C(i + ((n << 1) - y) - 1, (n << 1) - y) % MOD) %= MOD;
    else 
        for (int i = 1; i <= m; i++)
            (ans += C(i + (x - 1) - 1, x - 1) * C((m - i + 1) + (n - x) - 1, n - x) % MOD
                     * C((m - i + 1) + (y - n - 1) - 1, y - n - 1) % MOD * C(i + (n << 1) - y - 1, (n << 1) - y) % MOD) %= MOD;
    printf("%lld\n", ans);
    return 0;
}