#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 2e6 + 5;
int nxt[maxn][27], n;
LL f[maxn], ans;
char str[maxn];

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    scanf("%d\n%s", &n, str + 1);
    for (int i = n; i >= 1; i--) {
        int lst = 0;
        if (str[i] == str[i + 1]) {
            lst = i + 1;
        } else lst = nxt[i + 1][str[i] - 'a'];
        if (!lst) continue;
        f[i] = f[lst + 1] + 1;
        for (int j = 0; j < 26; j++) nxt[i][j] = nxt[lst + 1][j];
        nxt[i][str[i] - 'a'] = i;
        if (lst < n) nxt[i][str[lst + 1] - 'a'] = lst + 1;
    }
    for (int i = 1; i <= n; i++) ans += f[i];
    printf("%lld\n", ans);
    return 0;
}