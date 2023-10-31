#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL g(LL a, LL b) {
    if (a % b == 0) return 2 * a - b;
    LL t = a / b;
    return g(b, a % b) + 2 * t * b;
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    LL n, x; scanf("%lld%lld", &n, &x);
    LL a = x, b = n - x;
    if (a < b) printf("%lld\n", g(b, a) + a + b);
    else printf("%lld\n", g(a, b) + a + b);
    return 0;
}