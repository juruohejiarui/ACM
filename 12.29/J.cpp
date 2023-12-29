#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
vector<LL> ls1, ls2;

void getList(int x, int bs, vector<LL> &ls) {
    ls.clear();
    if (!x) ls.push_back(0);
    while (x) ls.push_back(x % bs), x /= bs;
}
void solve() {
    LL x, y, A, B; scanf("%lld%lld%lld%lld", &x, &y, &A, &B);
    if (x == y) {
        printf("YES\n2 2\n");
        return ;
    }
    // length == 2
    map<LL, pair<LL, LL> > mp;
    for (LL a = 1, to = a; a <= x; a = to + 1) {
        to = x / (x / a);
        mp[x / a] = make_pair(a, min(to, A));
    }
    for (LL b = 1, to = b; b <= y; b = to + 1) {
        to = y / (y / b);
        if (mp.count(y / b)) {
            LL y2 = y / b;
            if ((x - y) % y2) continue;
            LL rgl1 = mp[y / b].first, rgr1 = mp[y / b].second, rgl2 = b, rgr2 = min(to, B);
            LL dlt = (x - y) / y2;
            if (rgl1 - rgr2 <= dlt && dlt <= rgr1 - rgl2) {
                LL sol_b = rgl2, sol_a = sol_b + dlt;
                if (sol_a < rgl1) sol_b += rgl1 - sol_a, sol_a = rgl1;
                if (sol_a <= A && sol_a * sol_a > x && sol_b <= B && sol_b * sol_b > y) {
                    printf("YES\n%lld %lld\n", sol_a, sol_b);
                    return ;
                }
            } 
        }
    }
    map<vector<LL>, LL> mp2;
    for (LL bs = 2; bs <= A && bs * bs <= x; bs++) {
        getList(x, bs, ls1);
        mp2[ls1] = bs;
    }
    for (LL bs = 2; bs <= B && bs * bs <= y; bs++) {
        getList(y, bs, ls2);
        if (mp2.count(ls2)) {
            printf("YES\n%lld %lld\n", mp2[ls2], bs);
            return ;
        }
    }
    printf("NO\n");
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}