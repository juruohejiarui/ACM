#include <bits/stdc++.h>

using namespace std;

string solve(string &str) {
    string res;
    for (int i = 0; i < str.size(); i++) if (str[i] != '0') res.push_back(str[i]);
    return res;
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    string s1, s2, s3;
    cin >> s1 >> s2;
    int a1 = stoi(s1), a2 = stoi(s2), a3 = a1 + a2;
    s3 = to_string(a3);
    string s4 = solve(s1), s5 = solve(s2), s6 = solve(s3);
    int a4 = stoi(s4), a5 = stoi(s5), a6 = stoi(s6);
    if (a4 + a5 == a6) printf("YES\n");
    else printf("NO\n");
    return 0;
}