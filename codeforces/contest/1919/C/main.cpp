#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()

void solve() {
    vector<array<int, 2>> v;
    v.push_back({INT_MAX, INT_MAX});
    int N, res = 0;
    cin >> N;
    while (N--) {
        int X;
        cin >> X;
        if (v.back()[0] < X && v.back()[1] < X) {
            v[min_element(all(v.back())) - v.back().begin()]
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}