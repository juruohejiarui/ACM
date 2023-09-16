#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 5, maxm = 2e6 + 5;
struct Edge {
    int v, nex;
    Edge(int v = 0, int nex = 0) : v(v), nex(nex) {}
} E[maxm << 1];
int hd[maxn], tote = 1;
void addedge(int u, int v) {
    E[++tote] = Edge(v, hd[u]), hd[u] = tote;
    E[++tote] = Edge(u, hd[v]), hd[v] = tote;
}

int dfn[maxn], low[maxn], dfnc, did[maxn], didc, fl[maxm << 1];
void tarjan(int u, int frm) {
    dfn[u] = low[u] = ++dfnc;
    for (int i = hd[u]; i; i = E[i].nex) {
        int v = E[i].v;
        if (!dfn[v]) {
            tarjan(v, i);
            if (low[v] > dfn[u]) fl[i] = fl[i ^ 1] = 1;
            low[u] = min(low[u], low[v]);
        } else if (i != (frm ^ 1)) 
            low[u] = min(low[u], dfn[v]);
    }
}
vector<int> dls[maxn];
void dfs(int u) {
    dls[did[u] = didc].push_back(u);
    for (int i = hd[u]; i; i = E[i].nex) {
        int v = E[i].v;
        if (did[v] || fl[i]) continue;
        dfs(v);
    }
}
int n, m;

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v; scanf("%d%d", &u, &v);
        if (u == v) continue;
        addedge(u, v);
    }
    for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i, 0);
    for (int i = 1; i <= n; i++) if (!did[i])
        didc++, dfs(i);
    printf("%d\n", didc);
    for (int i = 1; i <= didc; i++) {
        printf("%ld ", dls[i].size());
        for (int j = 0; j < dls[i].size(); j++)
            printf("%d ", dls[i][j]);
        putchar('\n');
    }
    return 0;
}