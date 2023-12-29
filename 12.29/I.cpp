#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e6 + 5;
int readint() {
    int t = 0, m = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') m = -1; ch = getchar(); }
    while ('0' <= ch && ch <= '9')
        t = (t << 3) + (t << 1) + (ch - '0'), ch = getchar();
    return t * m;
}
int n, m;
inline int getid(int x, int y) { return x * m + y; }
int mp[maxn];
struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    bool operator < (const Point &b) const {
        return (x != b.x ? x < b.x : y < b.y);
    }
} p[maxn];

inline bool inRect(const Point &tl, const Point &br, const Point &p) {
    return tl.x <= p.x && p.x <= br.x && tl.y <= p.y && p.y <= br.y;
}

set<Point> pth;

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            mp[getid(i, j)] = readint(), p[mp[getid(i, j)]] = Point(i, j);
    int ans = 0;
    pth.clear();
    pth.insert(Point(1, 1)), pth.insert(Point(n, m));
    if (n == 1 && m == 1) {
        printf("1\n");
        return ;
    }
    
    for (int i = 0; i < n * m; i++) {
        if (mp[getid(1, 1)] == i || mp[getid(n, m)] == i) {
            ans = i + 1;
            continue;
        }
        auto liter = pth.upper_bound(p[i]);
        if (liter == pth.begin()) {
            ans = i + 1;
            continue;
        }
        auto riter = liter--;
        if (inRect(*liter, *riter, p[i])) {
            pth.insert(p[i]), ans = i + 1;
        } else break;
    }
    printf("%d\n", ans);
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}