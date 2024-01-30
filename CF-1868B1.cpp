#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 2e5 + 5;
int n;
LL avg, a[maxn], req[35], avl[35];


void solve() {
    scanf("%d", &n), avg = 0;
    for (int i = 0; i <= 30; i++) req[i] = avl[i] = 0;
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), avg += a[i];
    if (avg % n) {
        printf("No\n");
        return ;
    }
    avg /= n;
    bool succ = true;
    for (int i = 1; i <= n; i++) {
        a[i] = avg - a[i];
        if (!a[i]) continue;
        bool fl = false;
        if (a[i] < 0) a[i] = -a[i], fl = true;
        int lw = 0, hi = 0;
        while (!(a[i] & (1ll << lw))) lw++;
        hi = lw + 1;
        while (a[i] & (1ll << hi)) hi++;
        if (a[i] != (1ll << hi) - (1ll << lw)) {
            succ = false;
            break;
        }
        if (fl) swap(hi, lw);
        req[hi]++, avl[lw]++;
    }
    if (!succ) { printf("No\n"); return ; }
    for (int i = 0; i <= 30; i++) if (req[i] != avl[i]) {
        printf("No\n"); return ;
    }
    printf("Yes\n");
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}