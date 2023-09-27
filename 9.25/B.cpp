#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;
int n, a[maxn];
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        int t = a[i] & 1, fl = 0;
        for (int j = 1; j <= n; j++) if (i != j) {
            int tl = a[j] & 1;
            if (t == tl) { fl = 1; break; }
        }
        if (!fl) { printf("%d\n", i); break; }
    }
    return 0;
}