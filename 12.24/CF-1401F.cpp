#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 2.7e5 + 5;
int n, m;
int rev[20];
LL st[maxn << 2], a[maxn];
#define LS(o, dep) ((rev[dep]) ? ((o) << 1 | 1) : ((o) << 1))
#define RS(o, dep) ((rev[dep]) ? ((o) << 1) : ((o) << 1 | 1))

void init(int o, int l, int r, int dep) {
    if (l == r) { st[o] = a[l]; return ; }
    int mid = (l + r) >> 1;
    init(LS(o, dep), l, mid, dep - 1), init(RS(o, dep), mid + 1, r, dep - 1);
    st[o] = st[LS(o, dep)] + st[RS(o, dep)];
}
void mdfsig(int o, int l, int r, int p, int vl, int dep) {
    if (l == r) { st[o] = vl; return ; }
    int mid = (l + r) >> 1;
    if (p <= mid) mdfsig(LS(o, dep), l, mid, p, vl, dep - 1);
    else mdfsig(RS(o, dep), mid + 1, r, p, vl, dep - 1);
    st[o] = st[LS(o, dep)] + st[RS(o, dep)];
}

LL qry(int o, int l, int r, int ql, int qr, int dep) {
    if (qr < l || ql > r) return 0;
    if (ql <= l && r <= qr) return st[o];
    int mid = (l + r) >> 1;
    return qry(LS(o, dep), l, mid, ql, qr, dep - 1) + qry(RS(o, dep), mid + 1, r, ql, qr, dep - 1);
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n, m; scanf("%d%d", &n, &m);
    int sz = (1 << n);
    for (int i = 1; i <= sz; i++) scanf("%lld", &a[i]);
    init(1, 1, sz, 1);
    while (m--) {
        int c, a, b; scanf("%d%d", &c, &a);
        if (c == 1) {
            scanf("%d", &b);
            mdfsig(1, 1, sz, a, b, n);
        } else if (c == 2)
            for (int i = 0; i <= a; i++) rev[i] ^= 1;
        else if (c == 3) 
            rev[a + 1] ^= 1;
        else if (c == 4) {
            scanf("%d", &b);
            printf("%lld\n", qry(1, 1, sz, a, b, n));
        }
    }
    return 0;
}