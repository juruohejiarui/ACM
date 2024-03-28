#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 25;
const LL MOD = 1e9 + 7;

LL f[maxn][15], sf[maxn], pw10[maxn];

void calcF() {
    f[0][0] = 0, pw10[0] = 1;
    for (int i = 1; i <= 20; i++) {
        pw10[i] = pw10[i - 1] * 10 % MOD;
        for (int j = 0; j <= 9; j++) {
            f[i][j] = (sf[i - 1] + j * pw10[i - 1] % MOD) % MOD;
            (sf[i] += f[i][j]) %= MOD;
        }
    }
}

int a[maxn], lR;
LL ask(LL R) {
    if (!R) return 0;
    lR = 0;
    while (R) a[++lR] = R % 10, R /= 10;
    LL ans = 0;
    for (int i = 1; i < lR; i++) (ans += (sf[i] - f[i][0] + MOD) % MOD) %= MOD;
    LL pfx = 0;
    for (int i = lR; i > 0; i--) {
        for (int d = (i == lR); d < a[i]; d++)
            (ans += pfx * pw10[i - 1] % MOD + f[i][d]) %= MOD;
        pfx = (pfx + a[i]) % MOD;
    }
    (ans += pfx) %= MOD;
    return ans;
}

void solve() {
    LL l, r; scanf("%lld%lld", &l, &r);
    printf("%lld\n", (ask(r) - ask(l - 1) + MOD) % MOD);
}

int main() {
    freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    calcF();
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}