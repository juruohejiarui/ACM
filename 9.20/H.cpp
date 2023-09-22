#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 1e5 + 5;

char str[maxn]; int n, f[maxn][2];
void solve() {
    scanf("%s", str + 1), n = strlen(str + 1);
    LL ans = 0, s = 0;
    int cur = 1;
    if (str[1] == '1') s = 1;
    else s = 2;
    ans += s;
    for (int i = 2; i <= n; i++) {
        if (str[i] == str[i - 1]) s += ((i - 1) << 1);
        else s += (i - 1);
        if (str[i] == '1') s++;
        else s += 2;
        ans += s;
        // printf("%lld\n", ans);
    }
    printf("%lld\n", ans);
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}