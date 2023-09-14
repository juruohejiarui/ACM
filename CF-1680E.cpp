#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;

int readll() {
    int t = 0; char ch = getchar();
    while ('0' > ch || ch > '9') ch = getchar();
    while ('0' <= ch && ch <= '9') t = (t << 3) + (t << 1) + (ch - '0'), ch = getchar();
    return t;
}

struct Edge {
    int v, nex;
    Edge(int v = 0, int nex = 0) : v(v), nex(nex) {}
} E[maxn << 1];
int hd[maxn], tote;
void addedge(int u, int v) {
    E[++tote] = Edge(v, hd[u]), hd[u] = tote;
    E[++tote] = Edge(u, hd[v]), hd[v] = tote;
}

int n, m, fru, frv, ndt[maxn], dis[maxn], fat[maxn], c[2][maxn], tot[2];
inline int rev(int x) { return (x & 1) ? x + 1 : x - 1; }
void dfs1(int u, int fa) {
    for (int i = hd[u]; i; i = E[i].nex) {
        int v = E[i].v;
        if (v == fa) continue;
        if (ndt[v]) {
            if (dis[u] > dis[v]) {
                int t = (dis[u] - dis[v]) & 1;
                c[t][u]++, c[t][v]--, tot[t]++;
                if (!t) fru = v, frv = u;
            }
            continue;
        }
        fat[v] = u, ndt[v] = rev(ndt[u]), dis[v] = dis[u] + 1;
        dfs1(v, u);
    }
}
void dfs2(int u) {
    for (int i = hd[u]; i; i = E[i].nex) {
        int v = E[i].v;
        if (fat[v] != u) continue;
        dfs2(v), c[0][u] += c[0][v], c[1][u] += c[1][v];
    }
    if (c[0][u] == tot[0] && !c[1][u]) fru = u, frv = fat[u];
}
void dfs3(int u) {
    for (int i = hd[u]; i; i = E[i].nex) {
        int v = E[i].v;
        if (~ndt[v]) continue;
        if (fru == min(u, v) && frv == max(u, v)) continue;
        ndt[v] = ndt[u] ^ 1, dfs3(v);
    }
}

void solve() {
    for (int i = 1; i <= n; i++) hd[i] = c[0][i] = c[1][i] = ndt[i] = 0;
    tote = tot[0] = tot[1] = 0;
    n = readll(), m = readll();
    for (int i = 1; i <= m; i++) {
        int u = readll(), v = readll();
        addedge(u, v);
    }
    ndt[1] = 1, fru = frv = 0, dfs1(1, 0);
    if (tot[0] > 1) {
        fru = frv = 0, dfs2(1);
        if (!fru) { printf("NO\n"); return ; }
    }
    
    printf("YES\n");
    if (fru > frv) swap(fru, frv);
    for (int i = 1; i <= n; i++) ndt[i] = -1;
    ndt[1] = 0, dfs3(1);
    for (int u = 1; u <= n; u++) {
        bool fl = false;
        for (int i = hd[u]; i; i = E[i].nex) {
            int v = E[i].v;
            if (!ndt[u] && !ndt[v]) {
                fl = true;
                for (int j = 1; j <= n; j++) ndt[j] ^= 1;
                break;
            }
        }
        if (fl) break;
    }
    for (int i = 1; i <= n; i++) putchar(ndt[i] + '0');
    putchar('\n');
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T = readll();
    while (T--) solve();
    return 0;
}