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
}
