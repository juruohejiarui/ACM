#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;
inline int id(char ch) { return ch - 'a'; }
struct TrieNode {
    int ch[26], tot, cnt;
} nd[maxn];
int ndc;

void insert(char *str, size_t len) {
    int cur = 0;
    nd[0].tot++;
    for (size_t i = 0; i < len; i++) {
        if (!nd[cur].ch[id(str[i])]) nd[cur].ch[id(str[i])] = ++ndc;
        cur = nd[cur].ch[id(str[i])];
        nd[cur].tot++;
    }
    nd[cur].cnt++;
}

int tgr, succ;
char str[maxn], ans[maxn];

void dfs(int u, int sum, char *ans) {
    int c = 0;
    for (int i = 0; i < 26; i++)
        if (nd[u].ch[i]) c++;
    // printf("u = %d, c = %d, nd[u].cnt = %d\n", u, c, nd[u].cnt);
    if (sum + c + nd[u].cnt >= tgr) {
        *ans = '\0';
        succ = true;
        return ;
    }
    for (int i = 0; i < 26; i++) if (nd[u].ch[i]) {
        *ans = i + 'a';
        dfs(nd[u].ch[i], sum + nd[u].cnt + c - 1, ans + 1);
        if (succ) break;
        c += nd[nd[u].ch[i]].tot - 1;
        *ans = '\0';
    }
}

void solve() {
    ndc = 0, succ = 0;
    int n; scanf("%d%d", &n, &tgr);
    for (int i = 1; i <= n; i++)
        scanf("%s", str), insert(str, strlen(str));
    dfs(0, 0, ans);
    size_t ansl = strlen(ans);
    if (!ansl) printf("EMPTY\n");
    else printf("%s\n", ans);
    for (int i = 0; i <= ndc; i++) memset(nd[i].ch, 0, sizeof(nd[i].ch)), nd[i].tot = nd[i].cnt = 0;
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}