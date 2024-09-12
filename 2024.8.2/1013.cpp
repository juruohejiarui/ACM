#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL MOD = 1e9 + 7;

LL qpow(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD, b >>= 1;
    }
    return ret;
}

inline LL inv(LL n) { return qpow(n, MOD - 2); }

void solve() {
    LL n; scanf("%lld", &n);
    LL p1 = inv(n), p2 = (p1 + p1 % MOD * inv(n - 1) % MOD) % MOD;
    printf("%lld\n", (p1 + (1 - p1 + MOD) % MOD * (1 + inv(p2)) % MOD) % MOD);
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}