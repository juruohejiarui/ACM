#include <bits/stdc++.h>

using namespace std;

const int maxn = 805;
int n, m;
char hpC[7] = {'\0', 'A', 'B', 'C', 'D', 'E', '\0'};
char ans[maxn];

inline int getC(int lyr) { return (lyr - 1) % 5 + 1; }
inline int getLayer(int hp) { return hp / m + (hp % m > 0); }
inline int getPos(int hp) { return (hp - 1) % m + 1; }

void solve() {
    int hp, dmg; scanf("%d%d%d%d", &n, &m, &hp, &dmg);
    memset(ans, ' ', sizeof(ans));
    int tpL = getLayer(hp);
    if (tpL > 1) {
        char nxtLC = hpC[getC(tpL - 1)];
        for (int i = 1; i <= m; i++) ans[i] = nxtLC;
    }
    char tpLC = hpC[getC(tpL)];
    for (int i = 1; i <= getPos(hp); i++) ans[i] = tpLC;
    for (int cHp = hp, i = 0; cHp > hp - dmg && i <= m * 3; i++, cHp--) {
        ans[getPos(cHp)] = '.';
    }
    putchar('+');
    for (int i = 1; i <= m; i++) putchar('-');
    putchar('+');
    putchar('\n');
    for (int i = 1; i <= n; i++) {
        putchar('|');
        for (int j = 1; j <= m; j++) putchar(ans[j]);
        putchar('|');
        putchar('\n');
    }
    putchar('+');
    for (int i = 1; i <= m; i++) putchar('-');
    putchar('+');
    putchar('\n');
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();

    return 0;
}