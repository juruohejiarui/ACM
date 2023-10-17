#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 5, maxm = 1e6 + 5;

char mv[maxm];
int n, m, l, len, fl[maxn << 1][maxn << 1];
inline int getidx(int x) { return x + n; }
inline int getidy(int x) { return x + m; }
void solve() {
    scanf("%d%d%d\n%s\n", &n, &m, &l, mv + 1), len = strlen(mv + 1);
    int px = 0, py = 0;
    int tx = 0, ty = 0, sx = 1, ex = n, sy = 1, ey = m;
    int nl = (n << 1), ml = (m << 1);
    for (int i = 0; i <= nl; i++)
        for (int j = 0; j <= ml; j++) fl[i][j] = 0;
    fl[getidx(0)][getidy(0)] = 1;
    int rl = 1, rr = m, ru = 1, rd = n;
    for (int i = 1; i <= len; i++) {
        char ch = mv[i];
        if (ch == 'L') rl++, rr++, py++;
        else if (ch == 'R') rl--, rr--, py--;
        else if (ch == 'U') ru++, rd++, px++;
        else if (ch == 'D') ru--, rd--, px--;

        sx = max(sx, ru), ex = min(ex, rd);
        sy = max(sy, rl), ey = min(ey, rr);

        if (-n <= px && px <= n && -m <= py && py <= m)
            fl[getidx(px)][getidy(py)] = 1;
    }
    for (int i = 0; i <= nl; i++)
        for (int j = 0; j <= ml; j++) 
            fl[i][j] += (i ? fl[i - 1][j] : 0) + (j ? fl[i][j - 1] : 0) - (i && j ? fl[i - 1][j - 1] : 0);
    auto getsum = [](int x1, int y1, int x2, int y2) -> int {
        return fl[x2][y2] - (y1 ? fl[x2][y1 - 1] : 0) - (x1 ? fl[x1 - 1][y2] : 0) + (x1 && y1 ? fl[x1 - 1][y1 - 1] : 0);
    };
    if (ex < sx || ey < sy) { 
        if (!l) printf("%d\n", n * m);
        else printf("0\n");
        return ; 
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            int x1 = sx - i, x2 = ex - i, y1 = sy - j, y2 = ey - j;
            if ((ex - sx + 1) * (ey - sy + 1) - getsum(getidx(x1), getidy(y1), getidx(x2), getidy(y2)) == l)
                ans++;
        }
    printf("%d\n", ans);
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}