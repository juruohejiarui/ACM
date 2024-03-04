#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 25;

map<LL, LL> f[maxn][15];
int num[maxn], numl;

LL calcF(int P) {
    for (int i = 0; i <= numl; i++) 
        for (int x = 0; x <= 9; x++) f[i][x].clear();
    for (int i = 0; i <= 9; i++) f[1][i][(P - 1) * i] = 1ll;
    for (int i = 2; i <= numl; i++)
        for (int x = 0; x <= 9; x++)
            for (auto iter = f[i - 1][x].begin(); iter != f[i - 1][x].end(); iter++) {
                for (int y = 0; y <= 9; y++) if (iter->first + (P - i) * y >= 0)
                    f[i][y][iter->first + (P - i) * y] += iter->second;
            }
    LL res = 0;
    for (int i = 1; i <= numl; i++)
        for (int x = 1; x <= (i == numl ? num[numl] - 1 : 9); x++) 
            res += f[i][x][0];
    LL ts = (P - numl) * num[numl];
    for (int i = numl - 1; i >= 1; i--) {
        for (int x = 0; x < num[i]; x++) res += f[i][x][-ts];
        ts += (P - i) * num[i];
        if (ts > 0) break;
    }
    return res + (ts == 0);
}

LL solve(LL R) {
    if (!R) return 0;
    numl = 0;
    while (R) num[++numl] = R % 10, R /= 10;
    LL res = 0;
    for (int i = 1; i <= numl; i++) res += calcF(i);
    return res;
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    LL l, r; scanf("%lld%lld", &l, &r);
    printf("%lld\n", solve(r) - solve(l - 1));
    return 0;
}