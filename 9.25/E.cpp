#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
int n;
long long a[maxn], blen, b[maxn], c[maxn], to[maxn], f[maxn][2];

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        b[++blen] = a[i], c[blen] = 1;
        while (a[i + c[blen]] == a[i]) c[blen]++;
        i += c[blen] - 1;
    }
    b[0] = -1;
    for (int i = 1; i <= blen; i++) {
        f[i][0] = max(f[i - 1][0], f[i - 1][1]);
        f[i][1] = b[i] * c[i] + ((b[i - 1] == b[i] - 1) ? f[i - 1][0] : max(f[i - 1][0], f[i - 1][1]));
    }
    printf("%lld\n", max(f[blen][0], f[blen][1]));
    return 0;
}