#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> a(N);
    ll sum = 0;
    int neg_cnt = 0, abs_mn = 0;
    for (int& x : a) {
        cin >> x;
        neg_cnt += x < 0;
        abs_mn = min(abs_mn, abs(x));
    }

    if (neg_cnt & 1) {
        cout << sum - abs_mn;
    } else {
        cout << sum;
    }
}

