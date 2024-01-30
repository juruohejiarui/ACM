#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 5e5 + 5;

LL readll() {
    LL t = 0, m = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') m = -1; ch = getchar(); }
    while ('0' <= ch && ch <= '9')
        t = (t << 3) + (t << 1) + (ch - '0'), ch = getchar();
    return t * m;
}

int n, m, cl; LL a[maxn], b[maxn], c[maxn];

void solve() {
    scanf("%d%d", &n, &m), cl = 0;
    LL sa = 0, sb = 0, nly = 0;
    for (int i = 1; i <= n; i++) {
        a[i] = readll(), b[i] = readll();
        sa += a[i], sb += b[i];
        if (b[i] > a[i]) c[++cl] = b[i] - a[i];
        else nly = max(nly, a[i] - b[i]);
    }
    LL ans = sa;
    if (n == 1) {
        printf("%lld\n", b[1]);
        return ;
    }
    sort(c + 1, c + 1 + cl);
    c[cl + 1] = 0;
    LL op = n, res = n;
    while (cl > 0 && op < m) {
        ans += c[cl];
        op++, cl--, res--;
    }
    // res 1
    if (res == 1)
        ans = max(ans - c[cl + 1], ans - nly);
    if (2 * n - 1 <= m) ans = max(ans, sb);
    printf("%lld\n", ans);
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}