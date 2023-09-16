#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 4e3 + 5;
const LL MOD = 998244353;
int n, m;
LL f[2][maxn], sf[2][maxn], c[2][maxn], sc[2][maxn];

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    scanf("%d%d", &n, &m);
    c[0][0] = sc[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        int t = i & 1, tl = t ^ 1;
        for (int j = 0; j < m; j++) f[t][j] = c[t][j] = sf[t][j] = sc[t][j] = 0;
        for (int j = 1; j < m && j <= i; j++) {
            (f[t][j] += f[tl][j - 1] * (m - j + 1) % MOD) %= MOD;
            (c[t][j] += c[tl][j - 1] * (m - j + 1) % MOD) %= MOD;
            (f[t][j] += sf[tl][j] + MOD) %= MOD;
            (c[t][j] += sc[tl][j] + MOD) %= MOD;
        }
        (f[t][0] += (f[tl][m - 1] + c[tl][m - 1]) % MOD) %= MOD;
        (c[t][0] += c[tl][m - 1] % MOD) %= MOD;
        for (int j = m - 1; j >= 0; j--) 
            sf[t][j] = (sf[t][j + 1] + f[t][j]) % MOD,
            sc[t][j] = (sc[t][j + 1] + c[t][j]) % MOD;
    }
    printf("%lld\n", sf[n & 1][0]);
    return 0;
}