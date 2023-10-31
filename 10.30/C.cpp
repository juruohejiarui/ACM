#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 105;
int n, a[maxn], vis[maxn];
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), vis[i] = 0;
    bool succ = true;
    int mng = 1e6 + 5, p1, p2;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
            int g = gcd(a[i], a[j]);
            if (mng > g) p1 = i, p2 = j, mng = g;
        }
    vis[p1] = vis[p2] = 1;
    int cg = mng;
    if (cg > 2) { printf("No\n"); return ; }
    for (int i = 3; i <= n; i++) {
        mng = 1e6 + 5, p1 = 0;
        for (int j = 1; j <= n; j++) if (!vis[j]) {
            int g = gcd(cg, a[j]);
            if (g < mng) mng = g, p1 = j; 
        }
        vis[p1] = 1, cg = mng;
        if (cg > i) { printf("No\n"); return ; }
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