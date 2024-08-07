#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

bool f(const vector<int>& a, ll dt, int T) {
    ll result = 0;
    for (int x : a) {
        if ((result += dt / x) >= T) return 1;
    }
    return false;
}

int main() {
    int N, T;
    cin >> N >> T;
    vector<int> a(N);
    for (int& x : a) cin >> x;

    ll l = 0, r = 1e18;

    while (r - l > 1) {
        ll m = (l + r) / 2;

        if (f(a, m, T)) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << r;
}
