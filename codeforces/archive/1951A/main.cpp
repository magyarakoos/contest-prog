#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    vector<int> groupS({0});
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        if (groupS.back() && c != '1') {
            groupS.push_back(0);
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}