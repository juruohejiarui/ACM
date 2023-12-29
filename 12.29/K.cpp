#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
inline LL lowbit(LL x) { return x & -x; }
inline LL popcount(LL x) {
    LL cnt = 0;
    while (x) cnt++, x -= lowbit(x);
    return cnt;
}
inline LL chg(LL x, LL p) { return x ^ (1ll << (p - 1)); }
inline LL is1(LL x, LL p) { return (x >> (p - 1)) & 1; }
int n, m;
LL ans = 0;
inline int getid(int x, int y) { return (x - 1) * m + y; }

void dfs(LL sta) {
    ans = min(ans, popcount(sta));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) if (is1(sta, getid(i, j))) {
            for (int dx = -1; dx <= 1; dx++) if (i + abs(dx) <= n && i - abs(dx) >= 1)
                for (int dy = -1; dy <= 1; dy++) if (j + abs(dy) <= m && j - abs(dy) >= 1 && abs(dx) + abs(dy) <= 1) {
                    // printf("(%d, %d, %d, %d)", i, j, dx, dy);
                    if (is1(sta, getid(i + dx, j + dy)) != is1(sta, getid(i - dx, j - dy))) {
                        dfs(chg(chg(chg(sta, getid(i, j)), getid(i + dx, j + dy)), getid(i - dx, j - dy)));
                    }
                }
        }
}

void solve() {
    int k;
    scanf("%d%d%d", &n, &m, &k);
    ans = n * m;
    LL sta = 0;
    for (int i = 1; i <= k; i++) {
        int x, y; scanf("%d%d", &x, &y);
        sta = chg(sta, getid(x, y));
    }
    // printf("%lld %lld %lld\n", is1(sta, getid(1, 1)), is1(sta, getid(1, 2)), is1(sta, getid(1, 3)));
    dfs(sta);
    printf("%lld\n", ans);
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}