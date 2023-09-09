#include <bits/stdc++.h>

using namespace std;

const int maxn = 255, maxm = maxn * 1000, INF = 1e9;
int f[maxm], n, mnw, w[maxn], t[maxn], ls[maxn], m, vls_sz;
double vls[maxn];

int solve(int x) {
    double l = 0, r = maxm;
    auto calc = [&x](double vl) -> bool {
        vls_sz = 0;
        for (int i = 1; i <= n; i++) if (x != i) vls[++vls_sz] = t[i] - vl * w[i];
        sort(vls + 1, vls + n, [](double x, double y) { return x > y; });
        double s = t[x] - vl * w[x];
        if (s >= 0) return true;
        for (int i = 1; i < n; i++) {
            s += vls[i];
            if (s >= 0) return true;
        }
        return false;
    };
    while (r - l > 1e-5) {
        double mid = (l + r) / 2;
        if (calc(mid)) l = mid;
        else r = mid;
    }
    return l * 1000;
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    scanf("%d%d", &n, &mnw);
    int sw = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &w[i], &t[i]);
        if (w[i] < mnw) ls[++m] = i, sw += w[i];
    }
    for (int j = 1; j <= sw; j++) f[j] = -1e9;
    for (int i = 1; i <= m; i++)
        for (int j = sw; j >= w[ls[i]]; j--) f[j] = max(f[j], f[j - w[ls[i]]] + t[ls[i]]);
    int ans = 0;
    for (int j = mnw; j <= sw; j++) ans = max(ans, (int)(1000.0 * f[j] / j));
    for (int i = 1; i <= n; i++) if (w[i] >= mnw)
        ans = max(ans, solve(i));
    printf("%d\n", ans);
    return 0;
}