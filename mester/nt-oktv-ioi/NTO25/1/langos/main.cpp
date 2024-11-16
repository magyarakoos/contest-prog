#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> T(N);
    for (int& x : T) cin >> x;

    auto f = [&](ll x) -> bool {
        ll result = 0;
        for (int i = 0; i < N; i++) {
            result += x / T[i];
            if (result >= M) return 1;
        }
        return 0;
    };

    ll l = 0, r = 1e15;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        if (f(m)) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << r << " ";
    cout << r + *min_element(T.begin(), T.end()) << "\n";
}
