#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 5;
bitset<256> vis[maxn];
int n;
int ct[maxn], a1[maxn], a2[maxn];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
        string str; cin >> str;
        if (str == "add") ct[i] = 1, scanf("%d", &a1[i]);
        else if (str == "beq") ct[i] = 2, scanf("%d%d", &a1[i], &a2[i]), a2[i]--;
        else if (str == "bne") ct[i] = 3, scanf("%d%d", &a1[i], &a2[i]), a2[i]--;
        else if (str == "blt") ct[i] = 4, scanf("%d%d", &a1[i], &a2[i]), a2[i]--;
        else ct[i] = 5, scanf("%d%d", &a1[i], &a2[i]), a2[i]--;
    }
    int r = 0;
    bool lp = false;
    for (int i = 1; i <= n; i++) {
        if (vis[i][r]) {
            lp = true;
            break;
        }
        vis[i][r] = 1;
        switch(ct[i]) {
            case 1: (r += a1[i]) %= 256; break;
            case 2: 
                if (r == a1[i]) i = a2[i];
                break;
            case 3:
                if (r != a1[i]) i = a2[i];
                break;
            case 4: 
                if (r < a1[i]) i = a2[i];
                break;
            case 5:
                if (r > a1[i]) i = a2[i];
                break;
        }
    }
    if (lp) printf("No\n");
    else printf("Yes\n");
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}