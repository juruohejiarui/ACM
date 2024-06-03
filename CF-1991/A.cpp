#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) {
        int a, b; scanf("%d%d", &a, &b);
        if ((a + b) & 1) printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}