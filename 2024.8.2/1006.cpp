#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 5;

int f[545][545];

int F(int a, int b, int p = 0) {
    int vl = (1 << p);
    switch ((b >> p) % 4) {
        case 1 :
        case 3 :
            return (a - vl) % (vl << 1) != 0;
        case 2 :
            return (a - (vl << 1)) % (vl << 2) != 0;
    }
    return F(a, b, p + 1);
}

void solve() {
    int a, b, c; scanf("%d%d%d", &a, &b, &c);
    bool win = (F(a, b) || F(b, c) || F(c, a));
    printf("%s\n", (win ? "YES" : "NO"));
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}