#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int n, m; double p;
double check(int x) {
    return (1.0 * x * n + m) / (1.0 - pow(1 - p, x));
}

void solve() {
    scanf("%d%d%lf", &n, &m, &p), p /= 10000;
    int l = 1, r = 1e9;
    while (l + 2 < r) {
        int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        double v1 = check(m1), v2 = check(m2);
        // printf("%.3lf %.3lf\n", v1, v2);
        if (v1 < v2) r = m2;
        else l = m1;
    }
    printf("%.9lf\n", min(min(check(l), check(l + 1)), check(l + 2)));
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}