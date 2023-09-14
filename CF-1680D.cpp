#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 3e3 + 5;
int n; LL mxk, a[maxn], det[maxn], c[maxn];

int main() {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
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
        for (int j = i + 1; j <= n; j++) {
            
        }
    printf("%lld\n", ans);
    return 0;
}