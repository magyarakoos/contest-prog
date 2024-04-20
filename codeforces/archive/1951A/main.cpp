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
        if (c == '0') {
            if (groupS.back()) {
                groupS.push_back(0);
            }
        } else {
            groupS.back()++;
        }
    }
    if (!groupS.back()) groupS.pop_back();
    
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}