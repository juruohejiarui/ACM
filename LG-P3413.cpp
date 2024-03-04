#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 5e3 + 5;
const LL MOD = 1e9 + 7;
LL f[maxn][15][15], sf[maxn][15];

void calcF() {
    for (int i = 0; i <= 9; i++) f[1][i][10] = sf[1][i] = 1;
    for (int i = 2; i <= maxn - 5; i++)
        for (int a = 0; a <= 9; a++) {
            for (int b = 0; b <= 9; b++) if (a != b)
                f[i][a][b] = (sf[i - 1][b] - f[i - 1][b][a] + MOD * 2) % MOD,
                (sf[i][a] += f[i][a][b]) %= MOD;
        }
}


LL calcG(const string &str) {
    static int num[maxn];
    int len = str.size();
    if (len == 1) return 0;
    for (int i = 0; i < len; i++) num[len - i] = str[i] - '0';
    LL n = 0, res = 0;
    for (int i = len; i >= 1; i--) (n = n * 10 % MOD + num[i]) %= MOD;
    num[len + 1] = num[0] = 10;
    for (int i = 1; i < len; i++)
        for (int j = 1; j <= 9; j++) (res += sf[i][j]) %= MOD;
    for (int j = 1; j < num[len]; j++) (res += sf[len][j]) %= MOD;
    int fl = 1;
    for (int p = len; p >= 1; p--) {
        for (int x = 0; x < num[p - 1]; x++)
            if (x != num[p] && x != num[p + 1])
                (res += f[p][num[p]][x]) %= MOD;
        if (num[p - 1] == num[p] || num[p - 1] == num[p + 1]) { fl = 0; break; }
    }
    return (n - (res + fl) + MOD) % MOD;
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    string strL, strR;
    LL v1, v2;
    cin >> strL >> strR;
    int fl = 0;
    calcF();
    for (int i = 0; i < strL.size() - 1; i++)
        if (strL[i] == strL[i + 1] || (i + 2 < strL.size() && strL[i] == strL[i + 2])) {
            fl = 1;
            break;
        }
    printf("%lld\n", (calcG(strR) - calcG(strL) + fl + MOD) % MOD);
    return 0;
}