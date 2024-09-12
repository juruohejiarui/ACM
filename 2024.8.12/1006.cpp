#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5, maxm = 3e5 + 5;

int read() {
    int x = 0; char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while ('0' <= ch && ch <= '9') x = (x << 3) + (x << 1) + (ch - '0'), ch = getchar();
    return x;
}
void write(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (!x) { putchar('0'); return ; }
    static int dig[65], len;
    for (len = 0; x; x /= 10) dig[++len] = x % 10;
    for (int i = len; i >= 1; i--) putchar('0' + dig[i]);
}

struct UFS {
    vector<int> fa;
    int cnt;
    void init(int n) {
        fa.resize(n + 5);
        for (int i = 1; i <= n; i++) fa[i] = i;
        cnt = 0;
    }
    void clear() { fa.clear(); }
    int getfa(int u) { return fa[u] == u ? u : fa[u] = getfa(fa[u]); }
    void merge(int u, int v) {
        int fu = getfa(u), fv = getfa(v);
        if (fu == fv) return ;
        fa[fu] = fv;
        cnt++;
    }
    int chk(int u, int v) { return getfa(u) == getfa(v); }
} ufs[maxm];

int ui[maxm], vi[maxm], ans[maxm];
void solve() {
    int n = read(), m = read();
    int tr = m / (n - 1) + 2;
    for (int i = 1; i <= tr; i++) ufs[i].init(n);
    for (int i = 1; i <= m; i++) {
        ui[i] = read(), vi[i] = read();
        int l = 1, r = tr;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (ufs[mid].chk(ui[i], vi[i])) l = mid + 1;
            else r = mid - 1;
        }
        if (l > m / (n - 1)) ans[i] = -1;
        else {
            ans[i] = l;
            ufs[l].merge(ui[i], vi[i]);
        }
    }
    for (int i = 1; i <= m; i++) {
        if (ans[i] == -1) write(-1);
        else write(ufs[ans[i]].cnt < n - 1 ? -1 : ans[i]);
        putchar(' ');
    }
    putchar('\n');
    for (int i = 1; i <= tr; i++) ufs[i].clear();
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}