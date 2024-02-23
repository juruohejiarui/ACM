#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 2e5 + 5;
int n;
LL a[maxn], ls[maxn], c;

void solve() {
    scanf("%d%lld", &n, &c);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), ls[i] = i;
    sort(ls + 2, ls + 1 + n, [](int x, int y) { return a[x] - x * c > a[y] - y * c; });
    LL s = a[ls[1]]; bool succ = true; 
    for (int i = 2; i <= n; i++) {
        if (s + a[ls[i]] < ls[i] * c) { printf("No\n"), succ = false; break; }
        s += a[ls[i]];
    }
    if (succ) printf("Yes\n");
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}