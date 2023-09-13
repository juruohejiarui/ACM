#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 1e5 + 5;
const LL MOD = 998244353;

struct Matrix {
    LL a[2][2];
    LL* operator [] (int index) { return a[index]; }
    Matrix() { a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0; }
    friend Matrix operator * (Matrix a, Matrix b) {
        Matrix c; 
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) 
                for (int k = 0; k < 2; k++) (c[i][j] += a[i][k] * b[k][j] % MOD) %= MOD;
        return c;
    }
    friend Matrix operator + (Matrix a, Matrix b) {
        Matrix c;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) c[i][j] = (a[i][j] + b[i][j]) % MOD;
        return c;
    }
};

void solve(int k) {
    k = (k << 1) + 2;
    Matrix a, t; a[1][1] = 1, t[0][1] = t[1][0] = t[1][1] = 1;
    while (k) {
        if (k & 1) a = a * t;
        k >>= 1, t = t * t;
    }
    printf("%lld\n", a[1][1] - 1);
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int k;
    while (~scanf("%d", &k)) solve(k);
    return 0;
}