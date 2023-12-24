#include <bits/stdc++.h>

using namespace std;

typedef double LD;
const int maxn = 1e5 + 5;
struct STNode {
    LD mx; int c;
} nd[maxn << 2];
#define LS(o) (o << 1)
#define RS(o) (o << 1 | 1)

int updc(int o, int l, int r, LD bs) {
    if (nd[o].mx <= bs) return 0;
    if (l == r) return nd[o].mx > bs;
    int mid = (l + r) >> 1;
    if (nd[LS(o)].mx <= bs) return updc(RS(o), mid + 1, r, bs);
    return updc(LS(o), l, mid, bs) + nd[o].c - nd[LS(o)].c;
}

void pup(int o, int l, int r) {
    int mid = (l + r) >> 1;
    nd[o].c = nd[LS(o)].c + updc(RS(o), mid + 1, r, nd[LS(o)].mx);
    nd[o].mx = max(nd[LS(o)].mx, nd[RS(o)].mx);
}
void mdf(int o, int l, int r, int p, LD vl) {
    if (l == r) { nd[o].mx = vl, nd[o].c = 1; return ; }
    int mid = (l + r) >> 1;
    if (p <= mid) mdf(LS(o), l, mid, p, vl);
    else mdf(RS(o), mid + 1, r, p, vl);
    pup(o, l, r);
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n, m; scanf("%d%d", &n, &m);
    while (m--) {
        int p, h; scanf("%d%d", &p, &h);
        LD dt = 1.0 * h / p;
        mdf(1, 1, n, p, dt);
        printf("%d\n", nd[1].c);
    }
    return 0;
}