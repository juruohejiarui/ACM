#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
const int maxn = 1e4 + 5, maxm = 1e6 + 5;
int n, cx[maxn], cy[maxn];

inline LD dist(LD x1, LD y1, LD x2, LD y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

std::vector< std::tuple<int, int, int> > ansl;
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    LD cst;
    scanf("%d%Lf", &n, &cst);
    int sx, sy, ex, ey; LD ans = 0;
    scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &cx[i], &cy[i]);
    }
    ans = dist(ex, ey, sx, sy);
    ansl = {make_tuple(0, ex, ey)};
    for (int i = 1; i <= n; i++) {
        LD t1 = min(abs(cx[i] - sx), abs(cy[i] - sy)) + cst + min(abs(cx[i] - ex), abs(cy[i] - ey));
        if (t1 < ans) {
            ansl.clear();
            LD lsx, lsy;
            if (abs(cx[i] - sx) < abs(cy[i] - sy))
                ansl.push_back(make_tuple(0, cx[i], sy));
            else ansl.push_back(make_tuple(0, sx, cy[i])); 
            if (abs(cx[i] - ex) < abs(cy[i] - ey))
                ansl.push_back(make_tuple(i, cx[i], ey));
            else ansl.push_back(make_tuple(i, ex, cy[i]));
            ansl.push_back(make_tuple(0, ex, ey));
            ans = t1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) if (i != j) {
            LD t2 = min(abs(cx[i] - sx), abs(cy[i] - sy)) + cst + cst + min(abs(cx[j] - ex), abs(cy[j] - ey));
            if (t2 < ans) {
                ansl.clear();
                if (abs(cx[i] - sx) < abs(cy[i] - sy))
                    ansl.push_back(make_tuple(0, cx[i], sy));
                else ansl.push_back(make_tuple(0, sx, cy[i])); 
                ansl.push_back(make_tuple(i, cx[i], cy[j]));
                if (abs(cx[j] - ex) < abs(cy[j] - ey))
                    ansl.push_back(make_tuple(j, cx[j], ey));
                else ansl.push_back(make_tuple(j, ex, cy[j]));
                ansl.push_back(make_tuple(0, ex, ey));
                ans = t2;
            }
        }
    }
    printf("%.10Lf\n%ld\n", ans, ansl.size());
    for (int i = 0; i < ansl.size(); i++)
        printf("%d %d %d\n", get<0>(ansl[i]), get<1>(ansl[i]), get<2>(ansl[i]));
    return 0;
}