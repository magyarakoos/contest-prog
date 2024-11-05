#include <iostream>
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
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
