#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
// inline LL lcm(LL a, LL b) { return b / gcd(a, b) * a; }

void solve() {
    LL a, b; scanf("%lld%lld", &a, &b);
    if (a % b == 0) {
        printf("%lld %lld\n", b, a / b);
        return ;
    }
    printf("%lld %lld\n", b, 2 * a / gcd(2 * a, b));
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}