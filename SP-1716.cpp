#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e4 + 5, INF = 1e9;
int n, a[maxn];

struct STNode {
    int ls, rs, mx, s;
    STNode operator + (const STNode &o) const {
        STNode res;
        res.s = s + o.s;
        res.mx = max(max(mx, o.mx), rs + o.ls);
        res.ls = max(ls, s + o.ls);
        res.rs = max(o.rs, o.s + rs);
        return res;
    }
} nd[maxn << 2];

#define LS(o) (o << 1)
#define RS(o) (o << 1 | 1)

void init(int o, int l, int r) {
    if (l == r) { nd[o].ls = nd[o].rs = nd[o].mx = nd[o].s = a[l]; return ; }
    int mid = (l + r) >> 1;
    init(LS(o), l, mid), init(RS(o), mid + 1, r);
    nd[o] = nd[LS(o)] + nd[RS(o)];
}

void upd(int o, int l, int r, int p, int vl) {
    if (l == r) { nd[o].ls = nd[o].rs = nd[o].mx = nd[o].s = vl; return ; }
    int mid = (l + r) >> 1;
    if (p <= mid) upd(LS(o), l, mid, p, vl);
    else upd(RS(o), mid + 1, r, p, vl);
    nd[o] = nd[LS(o)] + nd[RS(o)];
}

STNode qry(int o, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return nd[o];
    int mid = (l + r) >> 1;
    if (qr <= mid) return qry(LS(o), l, mid, ql, qr);
    else if (ql > mid) return qry(RS(o), mid + 1, r, ql, qr);
    else return qry(LS(o), l, mid, ql, qr) + qry(RS(o), mid + 1, r, ql, qr);
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    init(1, 1, n);
    scanf("%d", &m);
    while (m--) {
        int t, x, y; scanf("%d%d%d", &t, &x, &y);
        if (t == 0) upd(1, 1, n, x, y);
        else printf("%d\n", qry(1, 1, n, x, y).mx);
    }
    return 0;
}