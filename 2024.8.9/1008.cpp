#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 205;
const LL MOD = 1e9 + 7;
int n;
struct Matrix {
    LL a[100][100];

    Matrix() { for (int i = 0; i < n; i++) memset(a[i], 0, sizeof(LL) * n); }
    Matrix(const Matrix &b) {
        for (int i = 0; i < n; i++) memcpy(a[i], b[i], sizeof(LL) * n); 
    }

    LL *operator [] (int index) { return a[index]; }
    const LL*operator [] (int index) const { return a[index]; }

    Matrix operator + (const Matrix &b) const {
        Matrix c;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                c[i][j] = (a[i][j] + b[i][j]) % MOD;
        return c;
    }

    Matrix operator * (const Matrix &b) const {
        Matrix c;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    (c[i][k] += a[i][j] * b[j][k] % MOD) %= MOD;
        return c;
    }
} I, A, B, C, fr0, toL, toR, tmp0;

Matrix qpow(const Matrix &a, LL p) {
    Matrix c = I, t = a;
    while (p) {
        if (p & 1) c = c * t;
        t = t * t, p >>= 1;
    }
    return c;
}

Matrix c[65]; LL kls[65], klsl;

Matrix calc(LL k, const Matrix &b) {
    klsl = 0;
    if (k == 0) return Matrix();
    while (k) kls[++klsl] = k, k >>= 1;
    Matrix s = b;
    for (int i = klsl - 1; i >= 1; i--)
        if (kls[i] & 1) c[i] = qpow(b, ((kls[i] / 2 + 1)));
        else qpow(b, kls[i] / 2);
    for (int i = klsl - 1; i >= 1; i--)
        if (kls[i] & 1) s = c[i] * (s + I) + s;
        else s = c[i] * s + s;
    return s;
}

LL f[maxn][maxn];

LL calcB(LL rg) {
    if (rg < 0) return 0;
    LL p = rg / n, ans = 0; 
    Matrix mtx;
    if (p > 0) {
        mtx = (A + I);
        if (p > 1) mtx = mtx + calc(p - 1, B) * (A + I);
        for (int i = 0; i < n; i++) (ans += mtx[0][i]) %= MOD;
    }
    mtx = qpow(B, p) * (A + I);
    for (int i = 0; i <= rg % n; i++) (ans += mtx[0][i]) %= MOD;
    return ans;
}
void solve() {
    int m; LL l, r; scanf("%d%d%lld%lld", &n, &m, &l, &r);
    l--, r--;
    memset(f, 0, sizeof(f)), I = Matrix();
    for (int i = 1; i <= m; i++) {
        int u, v; LL w; scanf("%d%d%lld", &u, &v, &w);
        u--, v--;
        f[u][v] = w;
    }
    
    for (int i = (n << 1) - 1; i >= 0; i--)
        for (int j = i + 1; j < (n << 1); j++)
            for (int k = i + 1; k < j; k++)
                (f[i][j] += f[i][k] * f[k][j] % MOD) %= MOD;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < (n << 1); j++)
            printf("f[%d,%d]=%lld%c", i, j, f[i][j], (j == (n << 1) - 1 ? '\n' : ' '));
    for (int i = 0; i < n; i++) I[i][i] = 1;
    fr0 = Matrix();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) A[i][j] = f[i][j], B[i][j] = f[i][j + n];
    }
    
    printf("%lld\n", (calcB(r) - calcB(l - 1) + MOD) % MOD);
}

int main() {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}