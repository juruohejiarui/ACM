#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL MOD = 1e9 + 7;
const int maxn = 80, maxm = 105;
int limK, C[maxm][maxm], num1[maxn], num2[maxn], numl;
LL f[maxn][2][2][2][2];

LL dfs(int p, int f1, int f2, int f3, int f4) {
    if (p == 1) return f1;
    if (f[p][f1][f2][f3][f4] != -1) return f[p][f1][f2][f3][f4];
    LL &s = f[p][f1][f2][f3][f4];
    s = 0;
    for (int x = 0; x <= (f2 ? limK - 1 : num1[p - 1]); x++) {
        int limY = min(f3 ? limK - 1 : num2[p - 1], f4 ? limK - 1 : x);
        for (int y = 0; y <= limY; y++)
            (s += dfs(p - 1, f1 | (C[x][y] == 0), f2 | (x < num1[p - 1]), f3 | (y < num2[p - 1]), f4 | (y < x))) %= MOD;
    }
    return s;
}

void solve() {
    memset(f, -1, sizeof(f));
    LL n, m;
    scanf("%lld%lld", &n, &m);
    numl = 0;
    while (n || m) num1[++numl] = n % limK, num2[numl] = m % limK, n /= limK, m /= limK;
    printf("%lld\n", dfs(numl + 1, 0, 0, 0, 0));
    
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d%d", &T, &limK);
    for (int i = 0; i <= limK; i++) C[i][0] = 1;
    for (int i = 1; i <= limK; i++)
        for (int j = 1; j <= limK; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % limK;
    while (T--) solve();
    return 0;
}