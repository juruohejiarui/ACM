#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxk = 64;
map< pair<LL, int>, LL> f;

LL calcF(LL n, LL k) {
    if (n <= 1) return n;
    auto pir = make_pair(n, k);
    if (f.count(pir)) return f[pir];
    LL vl = 0, mid;
    if (k == 0) {
        while (true) {
            vl++;
            if (n == 1) break;
            else n = n - (1 + n) / 2;
        }
    } else {
        mid = (1 + n) / 2;
        vl = calcF(mid - 1, k - 1) + calcF(n - mid, k) + 1;
    }
    f[pir] = vl;
    return vl;
}

void solve() {
    LL l, r, k; scanf("%lld%lld%lld", &l, &r, &k);
    if (k >= 64) {
        printf("%lld\n", r - l + 1);
        return ;
    }
    printf("%lld\n", calcF(r - l + 1, k));
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}