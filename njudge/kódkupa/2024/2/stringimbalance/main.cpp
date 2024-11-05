#include <algorithm>
#include <iostream>
#include <numeric>
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
        h[C - "a"[C < 'a']] += F;

        auto nh = h;
        sort(nh.begin(), nh.end());

        for (int i = 0; i < 51; i++) {
            if (K <= nh[i]) {
                nh[51] += K;
                break;
            } else {
                nh[51] += nh[i];
                K -= nh[i];
            }
        }

        ll sum = accumulate(nh.begin(), nh.end(), 0LL),
           result = 0;
        for (int i = 0; i < 52; i++) {
            result += h[i] * (sum - nh[i]);
        }

        cout << result << "\n";
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
