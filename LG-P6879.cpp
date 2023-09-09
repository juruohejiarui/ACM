#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 2e2 + 5;
const LL INF = 2e9;
int n, L;
struct Note {
    int p, t;
    friend bool operator < (Note a, Note b) {
        return a.p < b.p;
    }
} a[maxn];

LL f[maxn][maxn][maxn][2];
inline void updmin(LL& x, LL y) { x = min(x, y); }
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    scanf("%d%d", &n, &L);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i].p);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i].t);
    sort(a + 1, a + 1 + n);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= n; k++) 
                f[i][j][k][0] = f[i][j][k][1] = INF;
    f[0][0][0][0] = f[0][0][0][1] = 0; a[n + 1].p = L;
    for (int len = 0; len < n; len++)
        for (int l = 0; l <= len; l++) {
            int r = len - l; LL t, dis;
            for (int k = 0; k <= len; k++) {
                if (f[l][r][k][0] < INF) {
                    t = f[l][r][k][0];
                    if (l < n) updmin(f[l + 1][r][k + (t + a[n - l + 1].p - a[n - l].p <= a[n - l].t)][0], t + a[n - l + 1].p - a[n - l].p);
                    if (r < n) updmin(f[l][r + 1][k + (t + (L - a[n - l + 1].p + a[r + 1].p) <= a[r + 1].t)][1], t + (L - a[n - l + 1].p + a[r + 1].p)); 
                }
                if (f[l][r][k][1] < INF) {
                    t = f[l][r][k][1];
                    if (r < n) updmin(f[l][r + 1][k + (t + a[r + 1].p - a[r].p <= a[r + 1].t)][1], t + a[r + 1].p - a[r].p);
                    if (l < n) updmin(f[l + 1][r][k + (t + a[r].p + (L - a[n - l].p) <= a[n - l].t)][0], t + a[r].p + (L - a[n - l].p));
                }
            }
        }
    int ans = 0;
    for (int i = 0; i <= n; i++)
        for (int k = 0; k <= n; k++)
            if (f[i][n - i][k][0] < INF || f[i][n - i][k][1] < INF) ans = max(ans, k);
    printf("%d\n", ans);
    return 0;
} 