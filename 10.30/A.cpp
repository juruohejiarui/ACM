#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

void solve() {
    int a, b; scanf("%d%d", &a, &b);
    printf("%d\n", gcd(a, b));
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int a, b;
    while (~scanf("%d%d", &a, &b)) printf("%d\n", gcd(a, b));
    return 0;
}