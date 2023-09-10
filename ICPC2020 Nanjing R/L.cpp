#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, a[maxn], b[maxn];

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m), b[m + 1] = 1e9;
    int ans = 0;
    for (int i = 1; i <= m + 1; i++) {
        int pos1 = upper_bound(a + 1, a + 1 + n, b[i - 1]) - a,
            pos2, l = 1, r = n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (a[mid] < b[i]) l = mid + 1;
            else r = mid - 1;
        }
        pos2 = l - 1;
        ans = max(ans, pos2 - pos1 + 1);
    }
    if (ans) printf("%d\n", ans);
    else printf("Impossible\n");
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}