#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K, cash = 0, result = 0;
    cin >> N >> K;
    while (N--) {
        int x;
        cin >> x;
        if (x >= K) cash += x;
        if (x == 0) cash--, result++;
    }
    cout << result << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
