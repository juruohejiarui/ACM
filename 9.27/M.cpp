#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 2e3 + 5;
int n, ans;
struct Vector2 {
    LL x, y;
    Vector2() {}
    Vector2(LL x, LL y) : x(x), y(y) {}
} p[maxn];
Vector2 operator + (Vector2 a, Vector2 b) { return Vector2(a.x + b.x, a.y + b.y); }
Vector2 operator - (Vector2 a, Vector2 b) { return Vector2(a.x - b.x, a.y - b.y); }
Vector2 operator * (LL a, Vector2 b) { return Vector2(a * b.x, a * b.y); }
LL operator * (Vector2 a, Vector2 b) { return a.x * b.x + a.y * b.y; }
LL det(Vector2 a, Vector2 b) { return a.x * b.y - a.y * b.x; }

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld%lld", &p[i].x, &p[i].y);
    for (int i = 0, j = 0; i < n; i++) {
        while (p[j].y == p[i].y) j = (j + 1) % n;
        int pre = (i - 1 + n) % n;
        if (p[j].y > p[i].y && p[i].y < p[pre].y) {
            if (p[i].y != p[(i + 1) % n].y)
                ans += (det(p[i] - p[pre], p[j] - p[i]) > 0);
            else ans += (p[(i + 1) % n].x > p[i].x);
        }
    }
    printf("%d\n", ans);
    return 0;
}