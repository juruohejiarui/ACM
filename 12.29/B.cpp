#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 5e5 + 5;

LL readll() {
    LL t = 0, m = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') m = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9') t = (t << 3) + (t << 1) + (ch - '0'), ch = getchar();
    return t * m;
}
int n, m, q[maxn], ql, qr, mxl[maxn];
LL a[maxn], f[maxn];

void solve() {
    scanf("%d", &n), a[n + 1] = 0;
    for (int i = 1; i <= n; i++) a[i] = readll(), mxl[i] = 0;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int l = readll(), r = readll();
        mxl[r] = max(mxl[r], l);
    }
    q[ql = qr = 1] = 0;
    int rg = 0;
    for (int i = 1; i <= n + 1; i++) {
        while (ql < qr && q[ql] < rg) ql++;
        f[i] = f[q[ql]] + a[i];
        while (ql < qr && f[q[qr]] > f[i]) qr--;
        q[++qr] = i, rg = max(rg, mxl[i]);
    }
    printf("%lld\n", f[n + 1]);
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}