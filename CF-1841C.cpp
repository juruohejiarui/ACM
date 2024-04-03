#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 2e5 + 5;

char str[maxn];
LL fir[5], lst[5], w[5] = {1, 10, 100, 1000, 10000};

void solve() {
    scanf("%s", str + 1);
    int n = strlen(str + 1), mxd = 0;
    LL ans = 0;
    memset(fir, 0, sizeof(fir)), memset(lst, 0, sizeof(lst));
    for (int i = 1; i <= n; i++)
        fir[str[i] - 'A'] > 0 || (fir[str[i] - 'A'] = i),
        lst[str[i] - 'A'] = i;
    for (int i = n; i >= 0; i--)
        ans += (mxd > str[i] - 'A' ? -w[str[i] - 'A'] : w[str[i] - 'A']),
        mxd = max(mxd, str[i] - 'A');
    for (int c = 0; c < 5; c++) {
        for (int nc = 0; nc < c; nc++) {
            LL tmp = 0; int mxd = 0;
            for (int i = n; i >= 1; i--) {
                int dig = (i == lst[c] ? nc : str[i] - 'A');
                tmp += (mxd > dig ? -w[dig] : w[dig]);
                mxd = max(mxd, dig);
            }
            ans = max(ans, tmp);
        }
        for (int nc = c; nc < 5; nc++) {
            LL tmp = 0; int mxd = 0;
            for (int i = n; i >= 1; i--) {
                int dig = (i == fir[c] ? nc : str[i] - 'A');
                tmp += (mxd > dig ? -w[dig] : w[dig]);
                mxd = max(mxd, dig);
            }
            ans = max(ans, tmp);
        }
    }
    printf("%lld\n", ans);
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}