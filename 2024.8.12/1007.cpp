#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int chk(LL a, LL b, LL c, LL k) {
    static LL lsA[1005], lsB[1005], lsC[1005], lA, lB, lC;
    auto divNum = [&](LL num, LL *ls, LL &len) {
        len = 0;
        if (num == 0) ls[len = 1] = 0;
        else while (num) ls[++len] = num % k, num /= k;
    };
    divNum(a, lsA, lA);
    divNum(b, lsB, lB);
    divNum(c, lsC, lC);
    for (int i = 1; i <= max(max(lA, lB), lC); i++) {
        LL ai = (i > lA ? 0 : lsA[i]), bi = (i > lB ? 0 : lsB[i]), ci = (i > lC ? 0 : lsC[i]);
        if ((ai + bi) % k != ci) return 0;
    }
    return 1;
}

void solve() {
    LL a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    if (a + b == c) { printf("-1\n"); return ; }
    LL ans = 0, t = (LL)a + (LL)b - (LL)c;
    if (t <= 5) {
        for (int i = 2; i <= t; i++) if (t % i == 0) ans += chk(a, b, c, i);
    } else {
        ans += chk(a, b, c, t);
        for (int i = 2; i * i <= t; i++) {
            if (t % i) continue;
            ans += chk(a, b, c, i);
            if (i * i != t) ans += chk(a, b, c, t / i);
        }
    }
    printf("%lld\n", ans);
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}