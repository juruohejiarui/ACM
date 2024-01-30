#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
struct Edge {
    int v, nex, w;
    Edge(int v = 0, int w = 0, int nex = 0) : v(v), w(w), nex(nex) {}
} E[maxn << 1];
int hd[maxn], tote;
void addedge(int u, int v, int w) {
    E[++tote] = Edge(v, w, hd[u]), hd[u] = tote;
    E[++tote] = Edge(u, w, hd[v]), hd[v] = tote;
}
int rt, mxc[maxn], cnt[maxn], vl[maxn], f[maxn], h[maxn], w[maxn], g[maxn], lst[maxn];
struct Point {
    int v, vl;
    Point(int v, int vl) : v(v), vl(vl) {}
    friend bool operator < (Point a, Point b) { return a.vl < b.vl; }
};
priority_queue<Point> pq;
set<int> src[maxn];

void dfs1(int u, int fa) {
    if (mxc[u] == 1 && u != rt) return ;
    for (int i = hd[u]; i; i = E[i].nex) {
        int v = E[i].v;
        if (v == fa) continue;
        dfs1(v, u);
    }
    while (!pq.empty()) pq.pop();
    for (int i = hd[u]; i; i = E[i].nex) {
        int v = E[i].v;
        if (v == fa) continue;
        pq.push(Point(v, w[v] = h[v] + E[i].w));
    }
    for (; cnt[u] < mxc[u] - 2 && !pq.empty(); cnt[u]++, pq.pop())
        f[u] += pq.top().vl, src[u].insert(pq.top().v);
    h[u] = f[u];
    if (!pq.empty() && cnt[u] < mxc[u] - 1) {
        h[u] += pq.top().vl;
        if (u == rt) src[u].insert(pq.top().v), pq.pop();
    }
    lst[u] = (pq.empty() ? 0 : pq.top().v);
}

void dfs2(int u, int fa) {
    for (int i = hd[u]; i; i = E[i].nex) {
        int v = E[i].v;
        if (v == fa || mxc[v] <= 1) continue;
        g[v] = g[u] + E[i].w + f[u] + (src[u].count(v) ? w[lst[u]] - w[v] : 0);
        dfs2(v, u);
    }
}
 
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n; scanf("%d%d", &n, &rt);
    for (int i = 1; i < n; i++) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        addedge(u, v, w);
    }
    for (int i = 1; i <= n; i++) scanf("%d", &mxc[i]);
    dfs1(rt, 0);
    for (int i = hd[rt]; i; i = E[i].nex) {
        int v = E[i].v;
        if (mxc[v] <= 1) continue;
        if (src[rt].count(v)) g[v] = h[rt] + E[i].w - w[v] + w[lst[rt]];
        else g[v] = h[rt] + E[i].w;
        dfs2(v, rt);
    }
        
    int ans = 0;
    for (int i = 1; i <= n; i++) if (i != rt && mxc[i] > 1)
        ans = max(ans, g[i] + f[i]);
    if (mxc[rt] > 1) ans = max(ans, h[rt]);
    printf("%d\n", ans);
    return 0;
}
