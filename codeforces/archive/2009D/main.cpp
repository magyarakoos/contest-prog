#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    vector<array<bool, 2>> a(N + 1, {0, 0});
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }

    ll result = 0;

    for (int x = 0; x <= N; x++) {
        if (a[x][0] && a[x][1]) { result += N - 2; }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
