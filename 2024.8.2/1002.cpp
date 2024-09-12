#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int n, a[maxn], fl[maxn];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int hasStp1 = 0, ans = n + 1;
    sort(a + 1, a + 1 + n);
    if (n == 1) {
        printf("0\n");
        return ;
    }
    for (int i = 1; i <= n; i++) fl[i] = 0;

    for (int i = 1; i <= n; i++) if (!fl[i]) {
        int g = 0, mn = 1e9;
        for (int j = 1; j <= n; j++) if (!fl[j] && j != i) mn = min(mn, a[j]);
        g = mn;
        for (int j = 1; j <= n; j++) if (!fl[j] && j != i) g = gcd(g, a[j]);
        if (g == mn) ans = min(ans, n);
    }
    
    for (int i = 1; i <= n; i++) if (!fl[i])
        for (int j = i + 1; j <= n; j++) if (!fl[j]) {
            int res = a[j] % a[i];
            if (!res) break;
            int g = res;
            for (int k = 1; k <= n; k++) if (k != j && !fl[k]) g = gcd(g, a[k]);
            if (g == res) ans = min(ans, n);
        }
    int fl0 = 1;
    for (int i = 2; i <= n; i++) if (a[i] % a[1]) { fl0 = 0; break; }
    if (fl0) ans = min(ans, n - 1);
    for (int i = 1; i <= n; i++) if (!fl[i])
        for (int j = i + 1; j <= n; j++) if (!fl[j] && a[j] % a[i] == 0)
            fl[j] = 1;
    for (int i = 1; i <= n; i++) if (!fl[i]) {
        int g = 0, mn = 1e9;
        for (int j = 1; j <= n; j++) if (!fl[j] && j != i) mn = min(mn, a[j]);
        g = mn;
        for (int j = 1; j <= n; j++) if (!fl[j] && j != i) g = gcd(g, a[j]);
        if (g == mn) ans = min(ans, n);
    }
    
    for (int i = 1; i <= n; i++) if (!fl[i])
        for (int j = i + 1; j <= n; j++) if (!fl[j]) {
            int res = a[j] % a[i];
            if (!res) break;
            int g = res;
            for (int k = 1; k <= n; k++) if (k != j && !fl[k]) g = gcd(g, a[k]);
            if (g == res) ans = min(ans, n);
        }
    printf("%d\n", ans);
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}