#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    LL n, t, ans; scanf("%lld", &n);
    t = n / 3;
    ans = t * (t - 1) / 2 + t * (n - t);
    printf("%lld\n", ans);
    return 0;
}