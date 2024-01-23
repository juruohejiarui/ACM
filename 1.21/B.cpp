#include <bits/stdc++.h>

using namespace std;

int movR(int st, int dy, int &to) {
    int res = 1;
    res += (dy - (7 - st)) / 7 + ((dy - (7 - st)) % 7 != 0);
    to = (st + dy) % 7;
    return res;   
}

int movL(int st, int dy, int &to) {
    int res = (st > 0);
    res += (dy - st) / 7 + ((dy - st) % 7 != 0);
    to = ((st - dy) % 7 + 7) % 7;
    return res;
}

int getday(int yr, int id) {
    if (id == 2) {
        if (yr % 400 == 0 || (yr % 4 == 0 && yr % 100 != 0)) return 29;
        else return 28;
    } else {
        if (id == 4 || id == 6 || id == 9 || id == 11) return 30;
        else return 31;
    }
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    // start from 1.1.2023
    int st = 6, dy = 0, yr = 2023, id = 1;
    int tg; scanf("%d", &tg);
    if (tg >= yr) {
        for (; yr < tg; yr++) {
            for (int i = 1; i <= 12; i++)
                movR(st, getday(yr, i), st);
        }
        int ans = 0;
        for (int i = 1; i <= 12; i++) {
            printf("st = %d ", st);
            int tmp = movR(st, getday(yr, i), st);
            printf("%d\n", tmp);
            ans += tmp;
        }
        printf("%d\n", ans);
    } else {
        for (; yr - 1 > tg; yr--) {
            for (int i = 12; i >= 1; i--)
                movL(st, getday(yr, i), st);
        }
        int ans = 0;
        for (int i = 12; i >= 1; i--) {
            // printf("st = %d ", st);
            int tmp = movL(st, getday(yr - 1, i), st);
            // printf("%d\n", tmp);
            ans += tmp;
        }
        printf("%d\n", ans);
    }
    return 0;
}