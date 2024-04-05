#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
typedef long long LL;

const LL maxn = 1e6 + 5;

struct Vector2 {
    LL x, y;
    Vector2(LL x = 0, LL y = 0) : x(x), y(y) {};
    Vector2 operator + (const Vector2 &b) const { return Vector2(x + b.x, y + b.y); }
    Vector2 operator - (const Vector2 &b) const { return Vector2(x - b.x, y - b.y); }
    LL operator * (const Vector2 &b) { return x * b.y - y * b.x; }
} p[maxn];

inline LD area(const Vector2 &a, const Vector2 &b, const Vector2 &c) {
    return abs((b - a) * (c - a) / (LD)2.0);
}

void solve() {
    int n, m; scanf("%d%d", &n, &m);
    auto nxtPos = [&n](int a) -> int { return a % n + 1; };
    for (int i = 1; i <= n; i++) scanf("%lld%lld", &p[i].x, &p[i].y);
    for (int i = 1; i <= n; i++) p[i + n] = p[i];
    LD ans = 0, curA = 0;
    for (int i = 3; i <= m + 1; i++) curA += area(p[1], p[i - 1], p[i]);
    int aPos = m + 2;
    while ((p[m + 1] - p[1]) * (p[aPos] - p[1]) < (p[m + 1] - p[1]) * (p[nxtPos(aPos)] - p[1]))
        aPos = nxtPos(aPos);
    curA += area(p[1], p[m + 1], p[aPos]);
    ans = curA;
    // printf("f(%d) = %.3Lf, aPos = %d\n", 1, curA, aPos);
    for (int i = 2; i <= n; i++) {
        curA -= area(p[i - 1], p[m + i - 1], p[aPos]);
        while ((p[m + i] - p[i]) * (p[aPos] - p[i]) < (p[m + i] - p[i]) * (p[nxtPos(aPos)] - p[i]))
            aPos = nxtPos(aPos);
        curA += area(p[i], p[m + i], p[aPos]);
        curA += area(p[i], p[i + m], p[i + m - 1]) - area(p[i - 1], p[i], p[i + m - 1]);
        ans = max(ans, curA);
        // printf("f(%d) = %.3Lf, aPos = %d\n", i, curA, aPos);
    }
    printf("%.9Lf\n", ans);
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}