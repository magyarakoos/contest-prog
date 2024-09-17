#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    ll sum = 0, neg_cnt = 0, abs_mn = 1e18;
    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        sum += abs(x);
        neg_cnt += x < 0;
        abs_mn = min(abs_mn, abs(x));
    }

    if (neg_cnt & 1) {
        cout << sum - 2 * abs_mn;
    } else {
        cout << sum;
    }
}
