#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define cases 1
void solve() {
    map<int, int> m;
    int N;
    cin >> N;
    while (N--) {
        int X;
        cin >> X;
        m[X]++;
    }
    int result = 0;
    for (auto [_, val] : m) { result += val / 2; }
    cout << result << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
