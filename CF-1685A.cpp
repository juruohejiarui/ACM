#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int n, a[maxn], ans[maxn];
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    if (n & 1) { printf("NO\n"); return ; }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= (n >> 1); i++) 
        ans[(i << 1) - 1] = a[i], ans[i << 1] = a[i + (n >> 1)];
    ans[0] = a[n], ans[n + 1] = a[1];
    // bool fl = false;
    for (int i = 1; i <= n; i += 2) if (ans[i] >= ans[i - 1] || ans[i] >= ans[i + 1]) {
        printf("NO\n"); return ;
    }
    printf("YES\n");
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    putchar('\n');
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}