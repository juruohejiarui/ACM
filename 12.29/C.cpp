#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long LL;
const int maxn = 1e5 + 5;

LL readll() {
    LL t = 0, m = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') m = -1; ch = getchar(); }
    while ('0' <= ch && ch <= '9')
        t = (t << 3) + (t << 1) + (ch - '0'), ch = getchar();
    return t * m;
}
struct Point {
    LL a, b;
    friend bool operator < (Point a, Point b) {
        return a.a < b.a;
    }
} ls[maxn];
int n; 
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) ls[i].a = readll(), ls[i].b = readll();
    sort(ls + 1, ls + 1 + n);
    LL res = 0, ans = 0;
    for (LL i = n, p = 1; i >= p; i--) {
        res += ls[i].b;
        while (p < i && ls[p].b <= res) {
            ans += ls[p].b * (ls[i].a - ls[p].a);
            res -= ls[p].b;
            p++;
        }
        if (p < i && res <= ls[p].b)
            ans += res * (ls[i].a - ls[p].a), ls[p].b -= res, res = 0;
    }
    printf("%lld\n", ans);
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}