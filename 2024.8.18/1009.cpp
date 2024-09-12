#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;

char A[maxn], B[maxn];
int n, m, filA[maxn], filB[maxn];
int mxlA[maxn], mxlB[maxn];

void calcFil(char *A, int *fil, int n) {
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && A[i] != A[j + 1]) j = fil[j];
        if (A[i] == A[j + 1]) j++;
        fil[i] = j;
    }
}

int calcMxl(char *A, char *B, int *filB, int n, int m, int *mxl) {
    int cnt = 0;
    for (int i = 1, j = 0; i <= n; i++) {
        while (j == m || (j && B[j + 1] != A[i])) j = filB[j];
        if (A[i] == B[j + 1]) j++;
        mxl[i] = j;
        if (j == m) cnt++;
    }
    return cnt;
}

void solve() {
    scanf("%s %s", &A + 1, &B + 1);
    n = strlen(A + 1), m = strlen(B + 1);
    if (n < m) {
        for (int i = 1; i <= m; i++) swap(A[i], B[i]);
        swap(n, m);
    }
    memset(filA, 0, sizeof(int) * (max(n, m) + 1));
    memset(filB, 0, sizeof(int) * (max(n, m) + 1));
    calcFil(A, filA, n), calcFil(B, filB, m);
    int c1 = calcMxl(A, B, filB, n, m, mxlA), c2 = calcMxl(B, A, filA, m, n, mxlB);
    if (c1 > 1) { printf("-1\n"); return ; }
    
}
int main() {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    return 0;
}