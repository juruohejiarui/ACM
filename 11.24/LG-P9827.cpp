#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
const LD pi = acos(-1);

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n, m; scanf("%d%d", &n, &m);
    LD sc = 0, sr = 0, ans = 0;
    for (int i = 1; i < m; i++) {
        if (pi * i <= 2 * m) sc += pi * i / m;
        else sr += 2;
    }
    sc *= 2 * m, sr = sr * 2 * m + 2 * m;
    for (int i = 1; i <= n; i++) {
        ans += i * (sc + sr);
        for (int j = 1; j < i; j++)
            ans += 4 * m * m * (i - j) + (sc + sr) * 2 * j;
    }
    if (m > 1) for (int i = 1; i <= n; i++) ans += i * m * 2;
    printf("%.9Lf\n", ans);
    return 0;
}