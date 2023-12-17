#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e2 + 5, maxm = 1e3 + 5;
struct Node {
    map<string, int> children;
    int c_ign, c_kp;
} nd[maxn * maxm];
int ndcnt;

void add_ign(const string &path) {
    vector<string> prt;
    int lst = 0;
    for (int i = 0; i < path.size(); i++) if (path[i] == '/') 
        prt.push_back(path.substr(lst, i - lst)), lst = i + 1;
    prt.push_back(path.substr(lst, path.size() - lst));

    int cur = 0;
    for (int i = 0; i < prt.size(); i++) {
        if (!nd[cur].children.count(prt[i])) nd[cur].children[prt[i]] = ++ndcnt;
        cur = nd[cur].children[prt[i]];
        nd[cur].c_ign++;
    }
}

void add_kp(const string &path) {
     vector<string> prt;
    int lst = 0;
    for (int i = 0; i < path.size(); i++) if (path[i] == '/') 
        prt.push_back(path.substr(lst, i - lst)), lst = i + 1;
    prt.push_back(path.substr(lst, path.size() - lst));

    int cur = 0;
    for (int i = 0; i < prt.size(); i++) {
        if (!nd[cur].children.count(prt[i])) nd[cur].children[prt[i]] = ++ndcnt;
        cur = nd[cur].children[prt[i]];
        nd[cur].c_kp++;
    }
}

int calc(int nid) {
    if (nid) {
        if (!nd[nid].c_ign) return 0;
        if (nd[nid].c_kp == 0) return 1;
    }
    int ans = 0;
    for (auto &ele : nd[nid].children)
        ans += calc(ele.second);
    return ans;
}

void solve() {
    for (int i = 0; i <= ndcnt; i++) nd[i].children.clear(), nd[i].c_ign = nd[i].c_kp = 0;
    ndcnt = 0;
    int n, m; scanf("%d%d\n", &n, &m);
    for (int i = 1; i <= n; i++) {
        string path; getline(cin, path);
        add_ign(path);
    }
    for (int i = 1; i <= m; i++) {
        string path; getline(cin, path);
        add_kp(path);
    }
    printf("%d\n", calc(0));
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}