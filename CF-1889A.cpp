#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e2 + 5;
int n, f[maxn][maxn], op[maxn][maxn];
int als[maxn], alsl;
char s[maxn];
deque<char> sq;

void solve() {
    scanf("%d\n%s", &n, s + 1);
    int c0 = 0, c1 = 0;
    for (int i = 1; i <= n; i++) (s[i] == '1' ? c1++ : c0++);
    if (c1 != c0) { printf("-1\n"); return ; }
    alsl = 0;
    int dl = 0;
    for (int i = 1; i <= n; i++) sq.push_back(s[i]);
    while (sq.size() > 0) {
        if (sq.front() != sq.back()) dl++, sq.pop_front(), sq.pop_back();
        else {
            if (sq.front() == '0') 
                als[++alsl] = dl + sq.size(), dl++, sq.pop_front(), sq.push_back('0');
            else als[++alsl] = dl, dl++, sq.push_front('1'), sq.pop_back();
        }
    }
    printf("%d\n", alsl);
    for (int i = 1; i <= alsl; i++) printf("%d%c", als[i], i != alsl ? ' ' : '\n');
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}