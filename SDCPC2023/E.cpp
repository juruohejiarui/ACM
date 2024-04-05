#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

map<LL, LL> cst;
void solve() {
    cst.clear();
    LL n, m, k, a, b; scanf("%lld%lld%lld%lld%lld", &n, &k, &m, &a, &b);
    if (k == 1) {
        printf("%d\n", (n % m == 0 ? 0 : -1));
        return ;
    }
    for (LL curN = n, curCst = 0; ; curN /= k, curCst += b) {
        cst[curN] = curCst;
        if (curN == 0) break;
    }
    __int128_t ans = cst[0];
    for (auto &pir : cst) {
        for (__int128_t rgL = pir.first, rgR = pir.first, curCst = 0; 
            ; 
            rgL = rgL * k, rgR = rgR * k + k - 1, curCst += a) {
            if (rgR - rgL >= (rgL + m - 1) / m * m - rgL) {
                ans = min(ans, curCst + pir.second);
                break;
            }
        }
    }
    LL ans64 = ans;
    printf("%lld\n", ans64);
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}