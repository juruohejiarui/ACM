#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 3e5 + 5;
int n, p[maxn], vl[maxn]; LL C[4][maxn];

// 0P 1S 2S 3P 

inline void updAns(LL &ans, LL v) { ans = max(ans, v); }

inline void read(int &x) {
	char c = getchar(); x = 0;
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
}

inline int lowbit(int x) { return x & -x; }
void updP(LL *C, int x, LL vl) {
    for (; x <= n; x += lowbit(x)) C[x] = max(C[x], vl);
}
void updS(LL *C, int x, LL vl) {
    for (; x; x -= lowbit(x)) C[x] = max(C[x], vl);
}
LL getP(LL *C, int x) {
    LL ret = 0;
    for (; x > 0; x -= lowbit(x)) ret = max(ret, C[x]);
    return ret;
}
LL getS(LL *C, int x) {
    LL ret = 0;
    for (; x <= n; x += lowbit(x)) ret = max(ret, C[x]);
    return ret;
}

struct Query {
    int x, y, id;
    Query(int x = 0, int y = 0, int id = 0) : x(x), y(y), id(id) {}
    bool operator < (const Query &b) { return x < b.x; }
} q[4][maxn * 5];
int qcnt[4]; LL ans[maxn], tans[2][maxn], a[maxn];

void solve() {
    int m; read(n), read(m), qcnt[0] = qcnt[1] = qcnt[2] = qcnt[3] = 0;
    for (int i = 1; i <= n; i++) read(p[i]), read(vl[i]);
    for (int i = 1; i <= m; i++) {
        int xl, xr, yl, yr;
        read(xl), read(xr), read(yl), read(yr);
        ans[i] = 0;
        q[2][++qcnt[2]] = Query(xl - 1, yr + 1, i);
        q[3][++qcnt[3]] = Query(xr + 1, yl - 1, i);
        q[0][++qcnt[0]] = Query(xl - 1, yr + 1, i * 2);
        q[1][++qcnt[1]] = Query(xl - 1, yr + 1, i * 2);
        q[0][++qcnt[0]] = Query(xr + 1, yl - 1, i * 2 + 1);
        q[1][++qcnt[1]] = Query(xr + 1, yl - 1, i * 2 + 1);
    }
    sort(q[0] + 1, q[0] + 1 + qcnt[0]);
    sort(q[1] + 1, q[1] + 1 + qcnt[1]);
    for (int i = 0; i < 4; i++) memset(C, 0, sizeof(int) * (n + 5));
    for (int i = 1, px = 0; i <= qcnt[0]; i++) {
        while (px < q[0][i].x && px < n) {
            px++;
            a[px] = vl[px] + getP(C[0], p[px]);
            updP(C[0], p[px], a[px]);
        }
        tans[q[0][i].id & 1][q[0][i].id >> 1] = getP(C[0], q[0][i].y);
    }
    LL tmp = 0;
    for (int i = qcnt[1], px = n + 1; i >= 1; i--) {
        while (px > q[1][i].x && px > 1) {
            px--;
            LL t = getP(C[1], n - p[px] + 1);
            updP(C[1], n - p[px] + 1, t + vl[px]), a[px] += t;
        }
        tans[q[1][i].id & 1][q[1][i].id >> 1] += getP(C[1], n - q[0][i].y + 1);
    }
    for (int i = 1, px = 0; i <= qcnt[0]; i++) {
        while (px < q[2][i].x && px < n) {
            px++;
            updP(C[2], n - p[px] + 1, a[px]);
        }
        updAns(ans[q[2][i].id], getP(C[2], n - q[0][i].y + 1));
    }
    for (int i = qcnt[3], px = n + 1; i >= 1; i--) {
        while (px > q[3][i].x && px > 1) {
            px--;
            updP(C[3], p[px], a[px]);
        }
        updAns(ans[q[3][i].id], getP(C[3], q[0][i].y));
    }
    for (int i = 1; i <= m; i++) printf("%lld\n", max(max(ans[i], tans[0][i]), tans[1][i]));
}
int main() {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}