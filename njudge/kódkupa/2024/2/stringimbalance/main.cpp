#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    vector<ll> h(52);
    int Q;
    cin >> Q;
    while (Q--) {
        ll F, K;
        char C;
        cin >> F >> C >> K;
        C -= "aA"[C < 'a'];

        h[C] += F;

        auto nh = h;
        sort(nh.begin(), nh.end());
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
