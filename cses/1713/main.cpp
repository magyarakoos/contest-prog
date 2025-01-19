#include <bits/stdc++.h>
using namespace std;

int d(int n) {
    int result = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) { result += 1 + (i * i != n); }
    }
    return result;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int N, X;
    cin >> N;
    while (N--) {
        cin >> X;
        cout << d(X) << "\n";
    }
}
