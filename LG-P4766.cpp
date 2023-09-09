#include <bits/stdc++.h>

using namespace std;

const int maxn = 6e2 + 5;
struct Enemy {
    int l, r, d;
} a[maxn];
int n, m, pos[maxn << 1], f[maxn][maxn];

void solve() {
    scanf("%d", &n), m = 0;
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].d), pos[++m] = a[i].l, pos[++m] = a[i].r;
    sort(pos + 1, pos + 1 + m), m = unique(pos + 1, pos + 1 + m) - pos - 1;
    for (int i = 1; i <= n; i++)
        a[i].l = lower_bound(pos + 1, pos + 1 + m, a[i].l) - pos,
        a[i].r = lower_bound(pos + 1, pos + 1 + m, a[i].r) - pos;
    for (int i = 1; i <= m; i++)
        for (int j = i; j <= m; j++) f[i][j] = 1e9;
    for (int len = 1; len <= m; len++) {
        for (int l = 1; l + len - 1 <= m; l++) {
            int r = l + len - 1;
            int mxd = 0, mxdp = 0;
            for (int i = 1; i <= n; i++) if (a[i].l >= l && a[i].r <= r)
                mxd = (mxd < a[i].d ? a[mxdp = i].d : mxd);
            if (!mxdp) { f[l][r] = 0; continue; }
            for (int k = a[mxdp].l; k <= a[mxdp].r; k++)
                f[l][r] = min(f[l][r], f[l][k - 1] + f[k + 1][r] + mxd);
        }
    }
    printf("%d\n", f[1][m]);
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}