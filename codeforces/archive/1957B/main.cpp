#include <bits/stdc++.h>
using namespace std;

#define size(v) (int)v.size()

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> res;
    int sum = 0;
    for (int i = (1 << 30) ; i > 1; i /= 2) {
        if (i - 1 <= K) {
            
        }
    }
    for (int i = 0; i < N; i++) {
        if (i < size(res)) {
            cout << res[i] << " ";
        } else {
            cout << "0 ";
        }
    }
    cout << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}