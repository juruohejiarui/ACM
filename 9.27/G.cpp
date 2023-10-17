#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) {
        int cnt = 1, w = 1, cho1 = 0;
        int n, succ = true; scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int ai; scanf("%d", &ai);
            if (ai == 1) {
                cnt++, w++;
            } else if (ai == -1) {
                if (cnt == 1) { 
                    if (!cho1) succ = false; 
                    else cho1--, w++, cnt++;
                } else cnt--;
            } else {
                if (cnt == 1) cnt++, w++;
                else cho1++, cnt--;
            }
        }
        if (!succ) { printf("-1\n"); continue; }
        int g = gcd(cnt, w);
        printf("%d %d\n", w / g, cnt / g);
    }
    return 0;
}