#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    long long n, m, a; scanf("%lld%lld%lld", &n, &m, &a);
    printf("%lld\n", (long long)(ceil(1.0 * n / a) * ceil(1.0 * m / a)) );
    return 0;
}