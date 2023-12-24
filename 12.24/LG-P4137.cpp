#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
struct STNode {
    int ls, rs, c;
} nd[maxn * 20];
#define LS(o) (nd[o].ls)
#define RS(o) (nd[o].rs)
int ndc, rt[maxn];
void cpy(int &p, int o) { p = ++ndc, nd[p].ls = nd[o].ls, nd[p].rs = nd[o].rs; }

void ins(int &o, int src, int l, int r, int p, int vl) {
    cpy(o, src);
    if (l == r) { nd[o].c = vl; return ; }
    int mid = (l + r) >> 1;
    if (p <= mid) ins(LS(o), LS(src), l, mid, p, vl);
    else ins(RS(o), RS(src), mid + 1, r, p, vl);
    nd[o].c = min(nd[LS(o)].c, nd[RS(o)].c);
    // printf("%d,[%d, %d], %d\n", o, l, r, nd[o].c);
}

int qry(int rtr, int q, int l, int r) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (nd[LS(rtr)].c < q) return qry(LS(rtr), q, l, mid);
    else return qry(RS(rtr), q, mid + 1, r);
}

int a[maxn];

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n, m, mxa = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), mxa = max(mxa, a[i]);
    for (int i = 1; i <= n; i++) ins(rt[i], rt[i - 1], 1, mxa + 2, a[i] + 1, i);
    while (m--) {
        int l, r; scanf("%d%d", &l, &r);
        printf("%d\n", qry(rt[r], l, 1, mxa + 2) - 1);
    }
    return 0;
}