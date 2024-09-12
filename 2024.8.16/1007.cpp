#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int a[maxn], b[maxn], vis[maxn];

void solve() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) vis[i] = 0;
    int m1 = 0, m2 = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (vis[a[i]]) m1++;
        else vis[a[i]] = 1;
    }
    for (int i = 1; i <= n; i++) vis[i] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        if (vis[b[i]]) m2++;
        else vis[b[i]] = 1;
    }
    if (!m1) printf("sha7dow\n");
    else printf("shuishui\n");
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}