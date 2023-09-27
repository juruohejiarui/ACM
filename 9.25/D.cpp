#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n, cnt = 0, a[] = {1, 5, 10, 20, 100};
    scanf("%d", &n);
    for (int i = 4; i >= 0; i--) cnt += n / a[i], n %= a[i];
    printf("%d\n", cnt);
    return 0;
}