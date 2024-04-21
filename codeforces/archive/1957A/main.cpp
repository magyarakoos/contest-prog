#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    map<int, int> m;
    while (N--) {
        int X;
        cin >> X;
        m[X]++;
    }
    int result = 0;
    for (auto [k, v] : m) result += v / 3;
    cout << result << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}