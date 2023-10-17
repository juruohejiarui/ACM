#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int c[maxn], n;

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < 26; i++) c[i] = 0;
        string str; cin >> str;
        for (int i = 0; i < str.size(); i++)
            c[str[i] - 'a']++;
        int ans = str.size();
        for (int i = 0; i < 26; i++) ans = min(ans, (int)str.size() - c[i]);
        printf("%d\n", ans);
    }
    
    return 0;
}