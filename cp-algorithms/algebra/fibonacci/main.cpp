#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;

ll fib(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;

    ll a = 0;
    ll b = 1;
    ll tmp;
    for (int i = 2; i <= n; i++) {
        tmp = a + b;
        b = a;
        a = tmp;
    }

    return a;
}

int main(int argc, char* argv[]) {
    int n = stoi(argv[1]);

    cout << fib(n) << endl;
}
