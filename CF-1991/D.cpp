#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
int d[maxn], st[25][maxn], lg2[maxn];

inline int minp(int a, int b) { return d[a] <= d[b] ? a : b; }

inline int getMin(int l, int r) {
    int k = __lg(r - l + 1);
    return minp(st[k][l], st[k][r - (1 << k) + 1]);
}

bool solve(int l, int r, int dep) {
    if (l > r) return true;
    int mnp = getMin(l, r);
    if (d[mnp] != dep || !solve(l, mnp - 1, dep + 1)) return false;
    for (int to = mnp, nxt; to < r; to = nxt) {
        nxt = getMin(to + 1, r);
        if (d[nxt] != dep) return solve(to + 1, r, dep + 1);
        if (!solve(to + 1, nxt - 1, dep + 1)) return false;
    }
    return true;
}

void solve() {
    int n; scanf("%d", &n);
    int cnt0 = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &d[i]), st[0][i] = i, cnt0 += (d[i] == 0);
    for (int i = 1; i <= lg2[n] + 1; i++)
        for (int j = 1; j + (1 << i) - 1 <= n; j++)
            st[i][j] = minp(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);

    bool res = (cnt0 == 1 && solve(1, n, 0));
    printf("%s\n", (res ? "YES" : "NO"));
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    lg2[1] = 0;
    for (int i = 1; i < maxn; i++) lg2[i] = lg2[i >> 1] + 1;
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}