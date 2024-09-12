#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 5, MOD = 998244353;

int qpow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) ret = 1ll * ret * a % MOD;
        a = 1ll * a * a % MOD, b >>= 1;
    }
    return ret;
}
int lst_n, inv[maxn], fac[maxn], ifac[maxn];
void init_inv(int n) {
    if (inv[n]) return ;
    inv[1] = fac[0] = 1; 
    for (int i = max(2, lst_n); i <= n; i++) inv[i] = 1ll * (MOD - MOD / i) * inv[MOD % i] % MOD;
    for (int i = lst_n + 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
    ifac[n] = qpow(fac[n], MOD - 2);
    for (int i = n - 1; i > lst_n; i--) ifac[i] = ifac[i + 1] * (i + 1) % MOD;
    lst_n = n;
}

namespace Poly {
    int lsp[maxn], g, inv_g;
    int getsz(int n) {
        int res;
        for (res = 1; res < n; res <<= 1) ;
        return res;
    }
    inline void clr(int* f, int n) { memset(f, 0, sizeof(int) * n); }
    inline void cpy(int* dst, int* src, int n) { memcpy(dst, src, sizeof(int) * n); }
    void mul(int* f, int* g, int n) { for (int i = 0; i < n; i++) f[i] = 1ll * f[i] * g[i] % MOD; }
    int lstn;
    void init(int n) {
        if (lstn == n) return ;
        lstn = n, g = 3, inv_g = qpow(g, MOD - 2);
        for (int i = 0; i < n; i++) lsp[i] = (lsp[i>>1]>>1) | ((i&1)?(n>>1):0);
    }
    void ntt(int* f, int n, int fl) {
        init(n);
        for (int i = 0; i < n; i++) if (i < lsp[i]) 
            swap(f[i], f[lsp[i]]);
        for (int l = 2; l <= n; l <<= 1) {
            int buf = qpow((fl ? g : inv_g), (MOD - 1) / l), lsl = (l >> 1);
            for (int st = 0, w = 1; st < n; st += l, w = 1)
                for (int i = st; i < st + lsl; i++, w = 1ll * w * buf % MOD) {
                    int t = 1ll * w * f[i + lsl] % MOD;
                    f[i + lsl] = (f[i] - t + MOD) % MOD, (f[i] += t) %= MOD;
                }
        }
        if (!fl) {
            int t = qpow(n, MOD - 2);
            for (int i = 0; i < n; i++) f[i] = 1ll * f[i] * t % MOD;
        }
    }
    void times(int* f, int* g, int n, int res_n) {
        int m = getsz(n << 1);
        static int tmp[maxn];
        clr(tmp, m), cpy(tmp, g, n);
        ntt(f, m, 1), ntt(tmp, m, 1), mul(f, tmp, m), ntt(f, m, 0);
        clr(f + res_n, m - res_n), clr(tmp, m);
    }
    void inv(int* f, int* inv, int m) {
        int n = getsz(m);
        static int tmp[maxn], r[maxn], w[maxn];
        r[0] = qpow(f[0], MOD - 2);
        for (int l = 2; l <= n; l <<= 1) {
            for (int i = 0; i < (l >> 1); i++) w[i] = r[i];
            cpy(tmp, f, l), ntt(tmp, l, 1), ntt(w, l, 1);
            mul(w, tmp, l), ntt(w, l, 0), clr(w, l >> 1);
            cpy(tmp, r, l), 
            ntt(w, l, 1), ntt(tmp, l, 1), mul(w, tmp, l), ntt(w, l, 0);
            for (int i = (l >> 1); i < l; i++) r[i] = (2ll * r[i] - w[i] + MOD) % MOD;
        }
        cpy(inv, r, m), clr(tmp, n), clr(r, n), clr(w, n);
    }
    void sqrt(int* f, int* g, int m) {
        int n = getsz(m);
        static int b1[maxn], b2[maxn];
        b1[0] = f[0];
        for (int l = 2; l <= n; l <<= 1) {
            for (int i = 0; i < (l >> 1); i++) b2[i] = (b1[i] << 1) % MOD;
            inv(b2, b2, l), ntt(b1, l, 1), mul(b1, b1, l), ntt(b1, l, 0);
            for (int i = 0; i < l; i++) b1[i] = (b1[i] + f[i]) % MOD;
            times(b1, b2, l, l);
        }
        cpy(g, b1, m), clr(b1, (n << 1)), clr(b2, (n << 1));
    }
    void deri(int* f, int* g, int m) {
        for (int i = 1; i < m; i++) g[i - 1] = 1ll * f[i] * i % MOD;
        g[m - 1] = 0;
    }
    void inte(int* f, int* g, int m) {
        init_inv(m);
        for (int i = m - 1; i; i--) g[i] = 1ll * f[i - 1] * ::inv[i] % MOD;
        g[0] = 0;
    }
    void ln(int* f, int* g, int m) {
        static int df[maxn], invf[maxn];
        deri(f, df, m), inv(f, invf, m), times(df, invf, m, m), inte(df, g, m);
        clr(df, m), clr(invf, m);
    }
    void exp(int* f, int* g, int m) {
        static int e1[maxn], e2[maxn];
        int n = getsz(m);
        e1[0] = 1;
        for (int l = 2; l <= n; l <<= 1) {
            ln(e1, e2, l);
            for (int i = 0; i < l; i++) e2[i] = (f[i] - e2[i] + MOD) % MOD;
            e2[0] = (e2[0] + 1) % MOD;
            times(e1, e2, l, l);
        }
        cpy(g, e1, m), clr(e1, n), clr(e2, n);
    }
}
int f[maxn], g[maxn];
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &f[i]);
    Poly::exp(f, g, n);
    for (int i = 0; i < n; i++) printf("%d ", g[i]);
    return 0;
}