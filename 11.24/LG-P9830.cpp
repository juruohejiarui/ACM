#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
typedef long long LL;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

void solve() {
    LL n, m; scanf("%lld%lld", &n, &m);
    if (gcd(n, m) == 1) {
        printf("%.10Lf\n", sqrt(1.0L * n * n + 1.0L * m * m));
        return ;
    }
    LD ans = 2 * sqrt(1.0L * n * n + 1.0L * m * m);

    auto upd = [&ans, &n, &m](LL x0, LL y0) {
        if (x0 < 0 || x0 > n || y0 < 0 || y0 > m || gcd(x0, y0) > 1 || gcd(n - x0, m - y0) > 1) return ;
        if (x0 * (m - y0) == (n - x0) * y0) return ;
        ans = min(ans, sqrt(1.0L * x0 * x0 + 1.0L * y0 * y0) + sqrt(1.0L * (n - x0) * (n - x0) + 1.0L * (m - y0) * (m - y0)));
    };
    for (LL x0 = 0; x0 < n; x0++) {
        LL y0 = m - (n - x0) * m / n;
        upd(x0, y0 - 1), upd(x0, y0), upd(x0, y0 + 1);
    }
    printf("%.10Lf\n", ans);
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}
