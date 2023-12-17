#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 1.6e7 + 5;
const LL MOD = 1e9 + 7;
LL fac[maxn], ifac[maxn], inv[maxn];

void init(int n) {
    fac[0] = ifac[0] = inv[1] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
    for (int i = 2; i <= n; i++) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    for (int i = 1; i <= n; i++) ifac[i] = ifac[i - 1] * inv[i] % MOD;
}

inline LL C(int n, int m) { return fac[n] * ifac[m] % MOD * ifac[n - m] % MOD; }

void solve() {
    LL n, k; scanf("%lld%lld", &n, &k);
    printf("%lld\n", (C(n + (k >> 1) - 1, n) + C(n + ((k + 1) >> 1) - 1, n)) % MOD);
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    init(maxn - 1);
    while (T--) solve();
    return 0;
}