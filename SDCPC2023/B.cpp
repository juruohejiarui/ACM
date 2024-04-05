#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 1e5 + 5;
vector< pair<LL, int> > req[maxn];
LL reqC[maxn], cur[maxn], reqP[maxn];
queue<int> stfQ;

void upd(int t, int chg) {
    cur[t] += chg;
    while (reqP[t] < req[t].size() && req[t][reqP[t]].first <= cur[t]) {
        int cmpy = req[t][reqP[t]].second;
        reqC[cmpy]--, reqP[t]++;
        if (!reqC[cmpy]) stfQ.push(cmpy);
    }
}

map<int, int> tid;
int tidC;
int gettid(int x) { if (!tid.count(x)) tid[x] = ++tidC; return tid[x]; }
vector< pair<int, LL> > awrd[maxn];

LL initT[maxn], initN[maxn];

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) 
        scanf("%lld%lld", &initT[i], &initN[i]), initT[i] = gettid(initT[i]);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int sz, a; LL b;
        scanf("%d", &sz), reqC[i] = sz;
        for (int j = 0; j < sz; j++) 
            scanf("%d%lld", &a, &b), a = gettid(a),
            req[a].push_back(make_pair(b, i));
        if (!sz) stfQ.push(i);
        scanf("%d", &sz), awrd[i].resize(sz);
        for (int j = 0; j < sz; j++) scanf("%d%lld", &a, &b), awrd[i][j] = make_pair(gettid(a), b);
    }
    for (int i = 1; i <= tidC; i++) sort(req[i].begin(), req[i].end());
    for (int i = 1; i <= n; i++) upd(initT[i], initN[i]);
    int ans = 0;
    while (!stfQ.empty()) {
        int cmpy = stfQ.front(); stfQ.pop(), ans++;
        for (auto &pir : awrd[cmpy]) upd(pir.first, pir.second);
    }
    printf("%d\n", ans);
    return 0;
}