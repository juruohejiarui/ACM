#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 2e5 + 5;
const LL INF = 1e18;
int n;
vector<int> G[maxn], nd[maxn];
struct Edge {
    int v, nex;
    Edge(int v = 0, int nex = 0) : v(v), nex(nex) {}
} E[maxn << 1];
int hd[maxn], tck[maxn], ti, tote;

void clear() { ti++, tote = 0; }
void addedge(int u, int v) {
    // printf("%d %d\n", u, v);
    if (tck[u] != ti) tck[u] = ti, hd[u] = 0;
    if (tck[v] != ti) tck[v] = ti, hd[v] = 0;
    E[++tote] = Edge(v, hd[u]), hd[u] = tote;
    E[++tote] = Edge(u, hd[v]), hd[v] = tote;
}

int grd[maxn][20], mxd, dep[maxn], dfn[maxn], dfnc;
void dfs0(int u, int fa) {
    grd[u][0] = fa, mxd = max(mxd, dep[u] = dep[fa] + 1), dfn[u] = ++dfnc;
    nd[dep[u]].push_back(u);
    for (int v : G[u]) if (v != fa) dfs0(v, u);
}

void init0() {
    for (int i = 1; i <= mxd; i++) nd[i].clear();
    dfnc = mxd = 0, dfs0(1, 0);
    for (int i = 1; i <= 16; i++)
        for (int u = 1; u <= n; u++) grd[u][i] = grd[grd[u][i - 1]][i - 1];
}

int getlca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 16; i >= 0; i--) if (dep[grd[u][i]] >= dep[v]) u = grd[u][i];
    if (u == v) return u;
    for (int i = 16; i >= 0; i--) if (grd[u][i] != grd[v][i]) u = grd[u][i], v = grd[v][i];
    return grd[u][0];
}

int fl[maxn], kls[maxn], klslen;

int stk[maxn], stksz;
void build_vT() {
    sort(kls + 1, kls + 1 + klslen, [&](int x, int y) { return dfn[x] < dfn[y]; });
    // for (int i = 1; i <= klslen; i++) printf("%d ", kls[i]);
    // putchar('\n');
    clear(), stk[stksz = 1] = 1;
    for (int i = 1; i <= klslen; i++) {
        if (kls[i] == 1) continue;
        int u = kls[i], v = stk[stksz], lca = getlca(u, v);
        if (lca == v) stk[++stksz] = u;
        else {
            while (stksz > 1 && dep[lca] <= dep[stk[stksz - 1]])
                addedge(stk[stksz - 1], stk[stksz]), stksz--;
            if (lca != stk[stksz])
                addedge(lca, stk[stksz]), stk[stksz] = lca;
            stk[++stksz] = u;
        }
    }
    for (int i = stksz; i > 1; i--) addedge(stk[i], stk[i - 1]);
}

LL w[maxn], st[maxn][20]; int lg2[maxn];

void init1() {
    for (int i = 0; i < n; i++) st[i][0] = w[i];
    for (int i = 2; i <= n; i++) lg2[i] = lg2[i >> 1] + 1;
    for (int i = 1; i <= 16; i++)
        for (int j = 0; j + (1 << i) - 1 < n; j++)
            st[j][i] = min(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
            // printf("%lld%c", st[j][i], " \n"[j + (1 << i) - 1 == n - 1]);
}

LL qrymn(int l, int r) {
    return min(st[l][lg2[r - l + 1]], st[r - (1 << lg2[r - l + 1]) + 1][lg2[r - l + 1]]);
}

LL dp(int u, int fa, int mxd) {
    LL res = 0;
    for (int i = hd[u]; i; i = E[i].nex) {
        int v = E[i].v;
        if (v == fa) continue;
        res += dp(v, u, mxd);
    }
    if (!res) res = INF;
    res = min(res, qrymn(mxd - dep[u], mxd - dep[fa] - 1));
    return res;
}
LL calcly(int d) {
    klslen = 0;
    for (int x : nd[d]) kls[++klslen] = x;
    build_vT();
    return dp(1, 0, d);
}
void solve() {
    for (int i = 0; i <= n; i++) {
        G[i].clear(), fl[i] = 0;
        for (int j = 0; j <= 16; j++) st[i][j] = INF;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &w[i]);
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    init0(), init1();
    LL ans = w[0];
    for (int i = 2; i <= mxd; i++) ans += calcly(i);
    printf("%lld\n", ans);
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}