#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 3e3 + 5;
int n; LL mxk, a[maxn], det[maxn], c[maxn];

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    scanf("%d%lld", &n, &mxk);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        det[i] = det[i - 1] + a[i];
        c[i] = c[i - 1] + (!a[i]);
    }
    if (det[n] + c[n] * mxk < 0 || det[n] - c[n] * mxk > 0) {
        printf("-1\n");
        return 0;
    }
    LL ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++) {
            LL sp = det[j] - det[i - 1], sc = c[j] - c[i - 1];
            LL rdet = det[n] - sp, rc = c[n] - sc;
            ans = max(ans, min(abs(sp + sc * mxk), abs(rdet - rc * mxk)));
            ans = max(ans, min(abs(sp - sc * mxk), abs(rdet + rc * mxk)));
        }
    printf("%lld\n", ans + 1);
    return 0;
}