#include <bits/stdc++.h>

using namespace std;

int readll() {
    int t = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while ('0' <= ch && ch <= '9') t = (t << 3) + (t << 1) + (ch - '0'), ch = getchar();
    return t;
}
const int maxn = 1e5 + 5;
struct Edge {
    int v, nex, w;
} E[maxn << 1];
int hd[maxn], tote;
void addedge(int u, int v, int w) {
    ++tote, E[tote].v = v, E[tote].w = w, E[tote].nex = hd[u], hd[u] = tote;
    ++tote, E[tote].v = u, E[tote].w = w, E[tote].nex = hd[v], hd[v] = tote;
}
long long w[maxn], f[maxn][2];
void dfs(int u, int fa) {
    f[u][0] = f[u][1] = w[u];
    for (int i = hd[u]; i; i = E[i].nex) {
        int v = E[i].v;
        if (v == fa) continue;
        dfs(v, u);
        f[u][0] = min(f[u][0], f[v][0] + E[i].w);
        f[u][1] = max(f[u][1], f[v][1] - E[i].w);
    }
}

void solve() {
    memset(hd, 0, sizeof(hd)), tote = 0;
    int n = readll();
    for (int i = 1; i <= n; i++) w[i] = readll();
    // for (int i = 1; i <= n; i++) printf("%lld ", w[i]);
    // putchar('\n');
    for (int i = 1; i < n; i++) {
        int u = readll(), v = readll(), w = readll();
        addedge(u, v, w);
    }
    dfs(1, 0);
    long long ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, f[i][1] - f[i][0]);
    printf("%lld\n", ans);
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T = readll();
    while (T--) solve();
    return 0;
}