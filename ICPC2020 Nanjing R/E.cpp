#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 1e6 + 5;
int mv[5][2] = {{0,0}, {0,1}, {0,-1}, {1,0}, {-1,0}};
char mvc[5] = {' ', 'U', 'D', 'R', 'L'};
int p[maxn], c[5], mx, my;
char ls[maxn];

bool solve() {
    int x = 0, y = 0;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= c[p[i]]; j++) {
            x += mv[p[i]][0], y += mv[p[i]][1];
            if (mx == x && my == y) return false;
        }
    }
    return true;
}
int main() {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d\n%s\n", &mx, &my, ls + 1);
        c[1] = c[2] = c[3] = c[4] = 0;
        int n = strlen(ls + 1);
        for (int i = 1; i <= n; i++) {
            if (ls[i] == 'U') c[1]++;
            else if (ls[i] == 'D') c[2]++;
            else if (ls[i] == 'L') c[4]++;
            else c[3]++;
        }
        for (int i = 1; i <= 4; i++) p[i] = i;
        if ((mx == 0 && my == 0)) { printf("Impossible\n"); continue; }
        bool succ = false;
        do {
            if (solve()) {
                succ = true;
                for (int i = 1; i <= 4; i++)
                    for (int j = 1; j <= c[p[i]]; j++) putchar(mvc[p[i]]);
                putchar('\n');
                break;
            }
        } while (next_permutation(p + 1, p + 1 + 4));
        if (!succ) printf("Impossible\n");
    }
    return 0;
}