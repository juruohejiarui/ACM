#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
inline LL lcm(LL a, LL b) { return a / gcd(a, b) * b; }

void solve() {
    LL ti, a, b, c, d, v;
    scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &v, &ti);
    LL l = lcm(a, c);
    LL ans = 0, p1 = 0, p2 = 0; double lst = 0;
    if (l <= ti) {
        while (p1 < l || p2 < l) {
            int t = 0;
            if (p1 < l && p2 < l) {
                if (p1 + a <= p2 + c) t = 1, p1 += a;
                else t = 2, p2 += c;
            } else if (p1 < l) t = 1, p1 += a;
            else if (p2 < l) t = 2, p2 += c;
            if (t == 1) {
                if (lst + v + 0.5 >= p1) ans += b;
                else ans += b - 1;
            } else {
                if (lst + v + 0.5 >= p2) ans += d;
                else ans += d - 1;
            }
            if (t == 1) lst = p1;
            else lst = p2;
            // printf("- lst = %lf, ans = %lld p1 = %lld p2 = %lld\n", lst, ans, p1, p2);
        }
        ans = ans * (ti / l);
    }
    ans += b - 1 + d;
    ti %= l;
    p1 = 0, p2 = 0, lst = 0;
    while (p1 + a <= ti || p2 + c <= ti) {
        int t = 0;
        if (p1 + a <= ti && p2 + c <= ti) {
            if (p1 + a <= p2 + c) t = 1, p1 += a;
            else t = 2, p2 += c;
        } else if (p1 + a <= ti) t = 1, p1 += a;
        else if (p2 + c <= ti) t = 2, p2 += c;
        if (t == 1) {
            if (lst + v + 0.5 >= p1) ans += b;
            else ans += b - 1;
        } else {
            if (lst + v + 0.5 >= p2) ans += d;
            else ans += d - 1;
        }
        if (t == 1) lst = p1;
        else lst = p2;
        // printf("lst = %lf, ans = %lld p1 = %lld p2 = %lld\n", lst, ans, p1, p2);
    }
    printf("%lld\n", ans);
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}