#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 2e5 + 5;
const LL INF = 2e18;

struct Point {
	LL x, y;
	Point(LL x = 0, LL y = 0) : x(x), y(y) {}
} p[maxn];

inline LL sqr(LL x) { return x * x; }
inline LL dis(const Point &a, const Point &b) { return sqr(a.x - b.x) + sqr(a.y - b.y); }


LL solve(int l, int r) {
	if (l >= r) return INF;
	int mid = (l + r) >> 1;
	LL midx = p[mid].x, mnd = INF;
	LL res = min(solve(l, mid), solve(mid + 1, r));
	vector<Point> lls, rls(1, Point());
	for (int i = l; i <= mid; i++) if (sqr(midx - p[i].x) < res) lls.push_back(p[i]);
	for (int i = mid + 1; i <= r; i++) if (sqr(midx - p[i].x) < res) rls.push_back(p[i]);
	size_t rgl = 1, rgr = 0;
	for (size_t i = 0; i < lls.size(); i++) {
		while (rgr < rls.size() - 1 && (rls[rgr].y <= lls[i].y || sqr(rls[rgr + 1].y - lls[i].y) <= res)) rgr++;
		while (rgl <= rls.size() - 1 && rls[rgl].y < lls[i].y && sqr(rls[rgl].y - lls[i].y) > res) rgl++;
		for (size_t j = rgl; j <= rgr; j++) mnd = min(mnd, dis(lls[i], rls[j]));
	}
	rgl = l, rgr = mid + 1;
	lls.clear();
	while (rgl <= mid && rgr <= r) {
		if (p[rgl].y < p[rgr].y) lls.push_back(p[rgl++]);
		else lls.push_back(p[rgr++]);
	}
	while (rgl <= mid) lls.push_back(p[rgl++]);
	while (rgr <= r) lls.push_back(p[rgr++]);
	for (int i = l; i <= r; i++) p[i] = lls[i - l];
	return min(mnd, res);
}
int main() {
	// freopen("test.in", "r", stdin);
	// freopen("test.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld%lld", &p[i].x, &p[i].y);
	sort(p + 1, p + 1 + n, [](const Point &x, const Point &y) { return x.x < y.x; });
	printf("%.4lf\n", sqrt(solve(1, n)));
	return 0;
}