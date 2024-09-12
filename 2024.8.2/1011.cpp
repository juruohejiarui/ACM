#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL MOD = 998244353;

int n;
set<int> st;
void baoli(int x, int p) {
    if (p > n) {
        st.insert(x);
        return ;
    }
    baoli(x, p + 1);
    if (p > 1) x ^= (1 << (p - 2));
    x ^= (1 << (p - 1));
    if (p < n) x ^= (1 << p);
    baoli(x, p + 1);
}
LL qpow(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD, b >>= 1;
    }
    return ret;
}

void solve() {
    // int n;
    scanf("%d", &n);
    printf("%lld\n", qpow(2, n - (n % 3 == 2)));
    // st.clear();
    // baoli(0, 1);
    // printf("%ld\n", st.size());
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}