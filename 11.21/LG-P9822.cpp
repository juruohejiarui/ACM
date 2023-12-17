#include <bits/stdc++.h>

using namespace std;

typedef long double LD;

void solve() {
    LD n, p1, p2, v1, v2;
    scanf("%Lf%Lf%Lf%Lf%Lf", &n, &p1, &v1, &p2, &v2);
    if (p1 > p2) swap(p1, p2), swap(v1, v2);
    LD ans = min((n + min(n - p1, p1)) / v1, (n + min(n - p2, p2)) / v2);
    ans = min(ans, max((n - p1) / v1, p2 / v2));
    LD l = p1, r = p2;
    auto calc_l = [&n, &p1, &v1](LD p) {
        return min(2 * p - p1, p1 + p) / v1;
    };
    auto calc_r = [&n, &p2, &v2](LD p) {
        return min(n + p2 - 2 * p, 2 * n - p - p2) / v2;
    };
    while (r - l > 1e-10) {
        LD mid = (l + r) / 2;
        LD tl = calc_l(mid), tr = calc_r(mid);
        ans = min(ans, max(tl, tr));
        if (tl < tr) l = mid;
        else r = mid;
    }
    printf("%.9Lf\n", ans);
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}