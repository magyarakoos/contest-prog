#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll L, R;
    cin >> L >> R;
    vector<array<ll, 2>> result;
    while (L < R) {
        for (int i = 60; i >= 0; i--) {
            ll pw = (1LL << i);
            if (L % pw == 0 && L + pw <= R) {
                result.push_back({L, L + pw});
                L += pw;
                break;
            }
        }
    }
    cout << result.size() << "\n";
    for (auto [x, y] : result) cout << x << " " << y << "\n";
}
