#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
struct Point { int x, y; Point(int x = 0, int y = 0) : x(x), y(y) {} };
std::vector<Point> ls;

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n, m; bool swp = false;
    scanf("%d%d", &n, &m);
    if (n > m) swp = true, swap(n, m);
    for (int i = 1; i <= n; i++) ls.push_back(Point(i, 1));
    if (n != m) ls.push_back(Point(1, m));
    for (int i = 2; i < n; i++) ls.push_back(Point(i, m));
    if (n != m && n > 1) ls.push_back(Point(n, m));
    if (n & 1) {
        int sp = (n >> 1) + 1;
        for (int i = sp + 1; i <= m - sp; i++)
            ls.push_back(Point((1 + n) >> 1, i));
    } else {
        int sp = (n >> 1) + 1;
        for (int i = sp + 1; i <= m - sp; i += 2)
            ls.push_back(Point(n >> 1, i)),
            ls.push_back(Point((n >> 1) + 1, i));
    }
    printf("%ld\n", ls.size());
    for (auto &p : ls)
        if (swp) printf("%d %d\n", p.y, p.x);
        else printf("%d %d\n", p.x, p.y);
    return 0;
}