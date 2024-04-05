#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int n, v[maxn], w[maxn];

priority_queue<int, vector<int>, greater<int> > acQ, reqQ;
bool chk(int val) {
    while (!acQ.empty()) acQ.pop();
    while (!reqQ.empty()) reqQ.pop();
    for (int i = 1; i <= n; i++) {
        if (v[i] < val) reqQ.push(w[i]);
        else if (v[i] + w[i] > val) acQ.push(v[i] + w[i] - val);
    }
    while (!reqQ.empty()) {
        while (!acQ.empty() && acQ.top() < reqQ.top())
            acQ.pop();
        if (acQ.empty()) return false;
        reqQ.pop(), acQ.pop();
    }
    return true;
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &v[i], &w[i]);
    int l = 1, r = 1e9;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (chk(mid)) l = mid + 1;
        else r = mid - 1;
    }
    printf("%d\n", l - 1);
}
int main() {
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}