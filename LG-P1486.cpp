#include <bits/stdc++.h>

using namespace std;

const int maxn = 6e5 + 5, shift = 3e5, mxrg = (shift << 1);
struct STNode { int vl, lz; } nd[maxn << 2];
#define LS(o) (o << 1)
#define RS(o) (o << 1 | 1)

void pdw(int o) {
    if (!nd[o].lz) return ;
    nd[LS(o)].vl = nd[RS(o)].vl = 0;
    nd[LS(o)].lz = nd[RS(o)].lz = 1;
    nd[o].lz = 0;
}
inline void pdu(int o) { nd[o].vl = nd[LS(o)].vl + nd[RS(o)].vl; }

void ins(int o, int l, int r, int p) {
    if (l == r) { nd[o].vl++; return ; }
    int mid = (l + r) >> 1;
    pdw(o);
    if (p <= mid) ins(LS(o), l, mid, p);
    else ins(RS(o), mid + 1, r, p);
    pdu(o);
}
void clr(int o, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return ;
    if (ql <= l && r <= qr) { nd[o].lz = 1, nd[o].vl = 0; return ; }
    int mid = (l + r) >> 1;
    pdw(o);
    clr(LS(o), l, mid, ql, qr), clr(RS(o), mid + 1, r, ql, qr);
    pdu(o);
}
int getk(int o, int l, int r, int rk) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    pdw(o);
    if (nd[RS(o)].vl >= rk) return getk(RS(o), mid + 1, r, rk);
    else return getk(LS(o), l, mid, rk - nd[RS(o)].vl);
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int Q, mn, gchg = 0, ans = 0; scanf("%d%d\n", &Q, &mn);
    while (Q--) {
        char c = getchar();
        while (c != 'I' && c != 'A' && c != 'S' && c != 'F') c = getchar();
        int x, lst = 0; scanf("%d", &x);
        // printf("%c %d\n", c, x);
        lst = nd[1].vl;
        if (c == 'I') {
            ins(1, 0, mxrg, x - gchg + shift);
            if (mn - gchg + shift >= 0) clr(1, 0, mxrg, 0, mn - gchg + shift - 1);
            ans += max(lst - nd[1].vl, 0);
        } else if (c == 'A') gchg += x;
        else if (c == 'S') {
            gchg -= x;
            if (mn - gchg + shift >= 0) clr(1, 0, mxrg, 0, mn - gchg + shift - 1);
            ans += lst - nd[1].vl;
        } else {
            if (nd[1].vl < x) printf("-1\n");
            else printf("%d\n", getk(1, 0, mxrg, x) - shift + gchg);
        }
        
    }
    printf("%d\n", ans);
    return 0;
}