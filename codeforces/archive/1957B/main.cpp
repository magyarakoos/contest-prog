#include <bits/stdc++.h>
using namespace std;

#define size(v) (int)v.size()

void solve() {
    int N, K;
    cin >> N >> K;
    int res = 0;
    for (int i = (1 << 30) ; i > 1; i /= 2) {
        if (i - 1 <= K) {
            res = i - 1;
            break;
        }
    }
    cout << res;
    for (int i = 1; i < N; i++) cout << " 0";
    cout << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}