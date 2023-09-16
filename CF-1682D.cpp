#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
int ls[maxn << 1], n;

inline int id(int x) { return x > n ? x - n : x; }

void solve() {
    scanf("%d", &n);
    int c1 = 0;
    for (int i = 1; i <= n; i++) {
        char ch = getchar();
        while (ch != '0' && ch != '1') ch = getchar();
        ls[i] = ls[i + n] = ch - '0';
        c1 += (ch == '1');
    }
    if ((c1 & 1) || !c1) {
        printf("NO\n");
        return ;
    }
    if (c1 == n) {
        printf("YES\n");
        for (int i = 2; i <= n; i++) printf("1 %d\n", i);
        return ;
    }
    printf("YES\n");
    int rt = 1;
    for (int i = 2; i <= (n << 1); i++) if (ls[i - 1] && !ls[i]) {
        rt = i;
        break;
    }
    // printf("%d\n", rt);
    for (int i = rt + 1; i < rt + n; i++)
        if (!ls[i - 1]) printf("%d %d\n", id(i - 1), id(i));
    for (int i = rt + 1; i < rt + n; i++) if (ls[i - 1])
        printf("%d %d\n", id(rt), id(i));
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}