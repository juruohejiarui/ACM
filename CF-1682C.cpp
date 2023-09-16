#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int a[maxn], n;
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    int c1 = 0, c2 = 0;
    for (int i = 1; i <= n; i++) {
        int to = i;
        while (a[to + 1] == a[i]) to++;
        if (to != i) c2++;
        else c1++;
        i = to;
    }
    printf("%d\n", c2 + ((c1 + 1) >> 1));
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}