#include <bits/stdc++.h>

using namespace std;

int readll() {
    int t = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while ('0' <= ch && ch <= '9') t = (t << 3) + (t << 1) + (ch - '0'), ch = getchar();
    return t;
}
const int maxn = 2e6 + 5;
int a[maxn], sa[maxn], b[maxn], to[maxn], n;

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    while (~scanf("%d", &n)) {
        int pos = 0;
        for (int i = 1; i <= n; i++) a[i] = a[i + n] = readll();
        for (int i = 1; i <= n; i++) b[i] = b[i + n] = a[i] - readll();
        for (int i = 1; i <= (n << 1); i++) sa[i] = sa[i - 1] + a[i];
        int ans = 0;
        for (int i = 1; i <= n; i = to[i] + 1) {
            int s = b[i]; to[i] = i;
            while (s >= 0 && to[i] - i + 1 < n) s += b[++to[i]];
            if (ans < sa[to[i]] - sa[i - 1])
                pos = i - 1, ans = sa[to[i]] - sa[i - 1];
        }
        printf("%d\n", pos);
    }
    
    return 0;
}