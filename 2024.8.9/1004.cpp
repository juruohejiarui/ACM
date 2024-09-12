#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int n, stp, r1, r2;

struct Edge {
    int v, nex;
    Edge(int v = 0, int nex = 0) : v(v), nex(nex) {}
} E[maxn << 1];
int hd[maxn], tote;
void addedge(int u, int v) {
    E[++tote] = Edge(v, hd[u]), hd[u] = tote;
    E[++tote] = Edge(u, hd[v]), hd[v] = tote;
}

int mxwu, mxw;

void dfs(int u, int fa, int w) {
    if (w > mxw) { mxwu = u, mxw = w; }
    for (int i = hd[u]; i; i = E[i].nex) {
        int v = E[i].v;
        if (v != fa) dfs(v, u, w + 1);
    }
}

void solve() {
    scanf("%d%d%d%d", &n, &stp, &r1, &r2);
    tote = 0;
    for (int i = 1; i <= n; i++) hd[i] = 0;
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        addedge(u, v);
    }
    mxw = 0;
    dfs(stp, 0, 0);
    int ep1 = mxwu;
    mxw = 0, dfs(ep1, 0, 0);
    if (mxw <= 2 * r1) {
        printf("Kangaroo_Splay\n");
        return ;
    } else if (2 * r1 < r2) printf("General_Kangaroo\n");
    else printf("Kangaroo_Splay\n");
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}