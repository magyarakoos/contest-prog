#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> res;
    int sum = 0;
    for (int i = 1 ;; i *= 2) {
        if (sum + i <= K) {
            sum += i;
        } else {
            break;
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}