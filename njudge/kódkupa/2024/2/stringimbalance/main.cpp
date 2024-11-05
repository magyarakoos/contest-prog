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

        priority_queue<ll, vector<ll>, greater<ll>> pq;
        int mxi =
            max_element(h.begin(), h.end()) - h.begin();
        for (int i = 0; i < 52; i++) {
            if (i == mxi) continue;
            pq.push(h[i]);
        }
        ll mx = h[mxi];
        for (int i = 0; i < K; i++) {
            while (!pq.empty() && !pq.top()) pq.pop();
            if (pq.empty()) break;
            ll mn = pq.top();
            pq.pop();
            pq.push(mn - 1);
            mx++;
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
