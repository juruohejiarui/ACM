#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;
int n, m, gl, fl[maxn], pri[maxn], revp[maxn], pricnt;

void getpri(int n) {
    for (int i = 2; i <= n; i++) {
        if (!fl[i]) pri[++pricnt] = i;
        for (int j = 1; j <= pricnt && 1ll * i * pri[j] <= n; j++) {
            fl[i * pri[j]] = 1;
            if (i % pri[j] == 0) break;
        }
    }
}

int calc1() {
    int st = 1;
    while (pri[st] * pri[st] < n && st <= pricnt) st++;
    int c = gl;

    for (int i = st; i <= pricnt && pri[i] <= n && c > 0; i++) {
        if (n / pri[i] <= c) {
            c -= n / pri[i];
            for (int j = pri[i]; j <= n; j += pri[i]) revp[j] = 1;
        }
    }
    return (c > 0);
}

int f[205], w[205], mxp[205], idf[205];

int calc2() {
    if (n == 1) {
        if (gl == 1) printf("-1\n");
        else printf("1\n");
        return 1;
    }
    int st = 1, tc = 0;
    while (pri[st] * pri[st] <= n) st++;
    for (int i = 1; pri[i] <= n; i++)
        for (int j = pri[i]; j <= n; j += pri[i]) mxp[j] = i;
    for (int S = 0; S < (1 << (st - 1)); S++) {
        memset(revp, 0, (n + 1) * sizeof(int));
        memset(f, 0, (gl + 1) * sizeof(int));
        for (int i = 1; i < st; i++) 
            for (int j = pri[i]; j <= n; j += (pri[i] << 1))
                if (mxp[j] < st) revp[j] ^= ((S >> (i - 1)) & 1);
        tc = 0;
        for (int i = 1; i <= n; i++) tc += revp[i];
        if (tc > gl) continue;
        for (int i = st; pri[i] <= n; i++) {
            w[i] = 0;
            for (int j = pri[i]; j <= n; j += pri[i]) w[i] += 1 - revp[j / pri[i]];
        }
        f[tc] = 1;
        for (int i = st; pri[i] <= n; i++) {
            for (int j = gl; j >= tc; j--) if (!f[j] && f[j - w[i]])
                f[j] = 1, idf[j] = i;
        }
        if (f[gl]) break;
    }
    if (!f[gl]) { printf("-1\n"); return 1; }
    int cur = gl;
    while (cur > tc) {
        int p = pri[idf[cur]];
        for (int i = p; i <= n; i += p) revp[i] = 1 - revp[i / p];
        cur = cur - w[idf[cur]];
    }
    return 0;
}

void solve() {
    memset(revp, 0, (n + 1) * sizeof(int));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) revp[i] = 0;
    if ((n - m) % 2) { printf("-1\n"); return ; }
    gl = (n - m) >> 1;
    int res = 0;
    if (n >= 200) res = calc1();
    else res = calc2();

    if (res) return ;
    for (int i = 1; i <= n; i++) {
        if (revp[i]) putchar('-');
        putchar('1'), putchar(' ');
    }
    putchar('\n');
}

int main() {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    getpri(maxn - 5);
    while (T--) solve();
    return 0;
}