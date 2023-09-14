#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
char str[maxn]; int n, t[maxn];
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    scanf("%s", str + 1), n = strlen(str + 1);
    for (int i = 1; i <= n; i++) {
        switch (str[i]) {
            case 'b': t[i] = 1; break;
            case 'o': t[i] = 2; break;
            case 'y': t[i] = 3; break;
            case 'g': t[i] = (1 << 8) + 1; break;
            case 'i': t[i] = (1 << 8) + 2; break;
            case 'r': t[i] = (1 << 8) + 3; break;
            case 'l': t[i] = (1 << 8) + 4; break;
        }
    }
    int c1 = 0, c2 = 0;
    for (int i = 1; i <= n; i++) {
        if (!t[i]) continue;
        if (t[i + 1] != t[i] + 1) ((t[i] & (1 << 8)) ? c2 : c1)++;
    }
    printf("%d\n%d\n", c1, c2);
    return 0;
}