#include <bits/stdc++.h>
using namespace std;

#define size(v) (int)v.size()

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> res;
    int sum = 0;
    for (int i = 1 ;; i *= 2) {
        if (sum + i <= K) {
            sum += i;
            res.push_back(i);
        } else {
            break;
        }
    }
    for (int i = 0; i < N; i++) {
        if (i < size(rse))
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}