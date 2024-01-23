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
    int e, nex;
    Edge(int e = 0, int nex = 0) : e(e), nex(nex) {}
} E[maxn << 1];
int hd[maxn], tote;
inline void addedge(int u, int e) {
    E[++tote] = Edge(e, hd[u]), hd[u] = tote;
}
int n, m, q, eu[maxn], ev[maxn], qx[maxn], ans[maxn], vis[maxn], fl[maxn], qc[maxn];
char qt[maxn];
int eid[maxn];

void solve1(int x) {
    for (int i = 1; i <= n; i++) fl[i] = 0, eid[i] = 0;
    queue<int> q1, q0;
    for (int i = hd[x]; i; i = E[i].nex) {
        int e = E[i].e;
        if (eu[e] == x) eid[ev[e]] = e, q1.push(ev[e]);
        else eid[eu[e]] = e, q1.push(eu[e]);
    }
    for (int i = 1; i <= q; i++) {
        if (qt[i] == '?' && !ans[i]) {
            if (fl[x]) {
                while (!q1.empty() && (fl[q1.front()] || vis[eid[q1.front()]])) q1.pop();
                if (!q1.empty()) ans[i] = eid[q1.front()], vis[ans[i]] = 1, q1.pop();
            } else {
                while (!q0.empty() && (!fl[q0.front()] || vis[eid[q0.front()]])) q0.pop();
                if (!q0.empty()) ans[i] = eid[q0.front()], vis[ans[i]] = 1, q0.pop();
            }
        } else {
            fl[qx[i]] ^= 1;
            if (qx[i] == x || !eid[qx[i]] || vis[eid[qx[i]]]) continue;
            (fl[qx[i]] ? q0 : q1).push(qx[i]);
        }
    }
}

void solve2() {
    queue<int> que;
    for (int i = 1; i <= n; i++) fl[i] = 0;
    for (int i = 1; i <= q; i++) {
        if (qt[i] == '?' && !ans[i]) {
            while (!que.empty() && (vis[que.front()] || fl[eu[que.front()]] == fl[ev[que.front()]])) que.pop();
            if (!que.empty()) ans[i] = que.front(), vis[que.front()] = 1, que.pop();
        } else {
            fl[qx[i]] ^= 1;
            for (int j = hd[qx[i]]; j; j = E[j].nex) {
                int e = E[j].e;
                if (!vis[e] && fl[eu[e]] != fl[ev[e]]) que.push(e);
            }
            
        }
    }
}
std::vector< pair<int, int> > ls;
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    n = readll(), m = readll();
    for (int i = 1; i <= m; i++) {
        eu[i] = readll(), ev[i] = readll();
        addedge(eu[i], i), addedge(ev[i], i);
    }
    q = readll();
    for (int i = 1; i <= q; i++) {
        char ch = getchar();
        while (ch != '+' && ch != '-' && ch != '?') ch = getchar();
        qt[i] = ch;
        if (qt[i] != '?') qx[i] = readll(), qc[qx[i]]++;
    }
    for (int i = 1; i <= n; i++) ls.push_back(make_pair(-qc[i], i));
    sort(ls.begin(), ls.end());
    for (int i = 0; i < min(n, 400); i++) solve1(ls[i].second);
    solve2();
    for (int i = 1; i <= q; i++) if (qt[i] == '?') printf("%d\n", ans[i]);
    return 0;
}