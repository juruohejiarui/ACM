#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

void solve() {
    LL n, m, a, b;
    scanf("%lld%lld%lld%lld", &n, &m, &a, &b);
    if (n > m) swap(n, m), swap(a, b);
    if (n == 1) {
        printf("%lld\n", m);
        return ;
    }
    if ((a == 1 || a == n) && (b == 1 || b == m))
        printf("%lld\n", (n + m) * 2 - 4);
    else if (a == 1 || a == n)
        printf("%lld\n", (n + m) * 2 - 4 + (n - 2));
    else if (b == 1 || b == m)
        printf("%lld\n", (n + m) * 2 - 4 + (m - 2));
    else
        printf("%lld\n", ((n + m) * 2 - 4) + (max(n, m) - 2));
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}