#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    ll N, K;
    cin >> N >> K;

    vector<ll> p(N);
    for (ll& x : p) cin >> x;
    sort(p.rbegin(), p.rend());

    int avg = accumulate(p.begin(), p.end(), 0LL);
}
