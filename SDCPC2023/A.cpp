#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 1e2 + 5;

pair<int, int> obj[maxn];
void solve() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int ai, bi; scanf("%d%d", &ai, &bi);
        obj[i] = make_pair(ai, bi);
    }
    sort(obj + 1, obj + 1 + n);
    LL res = 0; int succ = true;
    for (int i = 1; i <= n; i++) {
        res += 1ll * (obj[i].first - obj[i - 1].first) * m;
        if (res < obj[i].second) { succ = false; break; }
        res -= obj[i].second;
    }
    printf("%s\n", succ ? "Yes" : "No");
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}