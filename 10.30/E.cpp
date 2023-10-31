#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;
int n, m, a[maxn], als[maxn], alsl;

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    scanf("%d%d", &m, &n);
    if (m == 1) { printf("1\n1\n1\n"); return 0; }
    if (n == 1) { printf("%d\n2\n%d 1\n", m, m - 1); return 0; }
    int ocnt = 0, p1 = 0, p2 = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if ((a[i] & 1) == 1) {
            ocnt++;
            if (p1) p2 = i;
            else p1 = i;
        }
    }
    if (ocnt > 2) { printf("Impossible\n"); return 0; }
    if (ocnt >= 1) swap(a[1], a[p1]);
    if (ocnt >= 2) swap(a[n], a[p2]);
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    putchar('\n');
    als[alsl = 1] = a[1] + 1;
    for (int i = 2; i < n; i++)
        als[++alsl] = a[i];
    // handle a[n]
    if (a[n] > 1) als[++alsl] = a[n] - 1;
    
    printf("%d\n", alsl);
    for (int i = 1; i <= alsl; i++) printf("%d ", als[i]);
    return 0;
}