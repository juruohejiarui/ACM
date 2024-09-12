#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

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

struct Trie { int ch[2], lzt, sz; } nd[maxn * 31];
int ndcnt, lzt;
vector<int> lz[64], lzid[64];
inline int newnd() {
    ndcnt++;
    nd[ndcnt].ch[0] = nd[ndcnt].ch[1] = 0;
    nd[ndcnt].lzt = lzt;
    nd[ndcnt].sz = 0;
    return ndcnt;
}

void applyLazy(int u, int dep);

int merge(int u, int v, int dep) {
    if (dep < -1) return u;
    if (!u || !v) return u | v;
    applyLazy(u, dep), applyLazy(v, dep);
    if (nd[u].sz < nd[v].sz) swap(u, v);
    nd[u].sz += nd[v].sz;
    nd[u].ch[0] = merge(nd[u].ch[0], nd[v].ch[0], dep - 1);
    nd[u].ch[1] = merge(nd[u].ch[1], nd[v].ch[1], dep - 1);
    return u;
}

void applyLazy(int u, int dep) {
    if (dep < 0 || lz[dep].size() == 0) return ;
    int l = 0, r = lz[dep].size() - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (lzid[dep][mid] <= nd[u].lzt) l = mid + 1;
        else r = mid - 1;
    }
    if (lz[dep].size() <= l) return ;
    for (int id = l; id < lz[dep].size(); id++) {
        switch (lz[dep][id]) {
            case 1:
                nd[u].ch[1] = merge(nd[u].ch[1], nd[u].ch[0], dep - 1), nd[u].ch[0] = 0;
                break;
            case 2:
                nd[u].ch[0] = merge(nd[u].ch[1], nd[u].ch[0], dep - 1), nd[u].ch[1] = 0;
                break;
            case 3:
                swap(nd[u].ch[0], nd[u].ch[1]);
                break;
        }
        nd[u].lzt = lzid[dep][id];
    }
}

void ins(int x) {
    int cur = 1;
    for (int i = 30; i >= 0; i--) {
        int d = (x >> i) & 1;
        applyLazy(cur, i);
        if (!nd[cur].ch[d]) nd[cur].ch[d] = newnd();
        cur = nd[cur].ch[d];
        nd[cur].sz++;
    }
}

int ask(int x) {
    int cur = 1, ans = 0;
    for (int i = 30; i >= 0; i--) {
        int d = (x >> i) & 1;
        applyLazy(cur, i);
        if (!nd[cur].ch[d ^ 1]) cur = nd[cur].ch[d];
        else ans |= (1 << i), cur = nd[cur].ch[d ^ 1];
    }
    return ans;
}

void solve() {
    ndcnt = 0, lzt = 0;
    for (int i = 0; i <= 30; i++) lz[i].clear(), lzid[i].clear();
    int n = read(), m = read();
    newnd();
    for (int i = 1; i <= n; i++) { int pi = read(); ins(pi); }
    for (int i = 1; i <= m; i++) {
        int op = read(), a = read();
        switch (op) {
            case 1: ins(a); break;
            case 2: 
                lzt++;
                for (int i = 0; i <= 30; i++) if (a & (1 << i))
                    lz[i].push_back(1), lzid[i].push_back(lzt);
                break;
            case 3:
                lzt++;
                for (int i = 0; i <= 30; i++) if (!(a & (1 << i)))
                    lz[i].push_back(2), lzid[i].push_back(lzt);
                break;
            case 4:
                lzt++;
                for (int i = 0; i <= 30; i++) if (a & (1 << i))
                    lz[i].push_back(3), lzid[i].push_back(lzt);
                break;
            case 5:
                printf("%d\n", ask(a)); break;
        }
    }
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}