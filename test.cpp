#include <bits/stdc++.h>

using namespace std;

int fib(int n) {
    printf("f(%d)", n);
    return fib(n - 1) * fib(n - 2);
}
int main() {
    fib(100);
    return 0;
}