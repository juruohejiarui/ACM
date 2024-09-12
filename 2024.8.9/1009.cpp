#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 1e5 + 5;
const LL INF = 1e9;

int n, tgr, p[maxn]; LL t[maxn];
struct Edge {
    int v, nex; LL x;
    Edge(int v = 0, LL x = 0, int nex = 0) : v(v), x(x), nex(nex) {} 
} E[maxn << 1];
int hd[maxn], tote;
void addedge(int u, int v, LL w) {
    E[++tote] = Edge(v, w, hd[u]), hd[u] = tote;
}

LL f[maxn][2];
void dp(int u) {
    f[u][0] = (p[u] ? 0 : t[u]), f[u][1] = INF;
    for (int i = hd[u]; i; i = E[i].nex) {
        int v = E[i].v;
        dp(v);
        LL  new0 = f[u][0] + f[v][0] * E[i].x,
            new1 = min(f[u][1] + f[v][0] * E[i].x, f[u][0] + min(f[v][0], f[v][1]) * E[i].x);
        f[u][0] = min(new0, INF);
        f[u][1] = min(new1, INF);
    }
    if (u != tgr) f[u][1] = min(f[u][1], 0ll);
}

void solve() {
    scanf("%d%d", &n, &tgr);
    tote = 0;
    for (int i = 0; i <= n; i++) hd[i] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        if (!p[i]) scanf("%lld", &t[i]);
        else {
            int nc; scanf("%d", &nc);
            for (int j = 1; j <= nc; j++) {
                int u; LL x; scanf("%lld%d", &x, &u);
                addedge(i, u, x);
            }
        }
    }
    dp(tgr);
    if (min(f[tgr][0], f[tgr][1]) >= INF) printf("Impossible\n");
    else printf("%lld\n", min(f[tgr][0], f[tgr][1]));
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}