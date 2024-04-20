#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    vector<bool> v(N);
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        v[i] = c == '1';
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (abs(i - j) <= 1) continue;
            if (v[i] && v[j]) {
                
            }
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}