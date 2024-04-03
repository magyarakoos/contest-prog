#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, K;
    cin >> N >> K;
    vector<ll> v(N);
    for (ll& x : v) cin >> x;

    priority_queue<ll, vector<ll>, greater<ll>> pq(v.begin(), v.end());

    ll result = 0;

    while (!pq.empty()) {
        ll x = pq.top();
        result += x;
        vector<ll> incr;
        for (int i = 0; i < K && !pq.empty(); i++) {
            incr.push_back(pq.top() + x);
            pq.pop();
        }
        for (ll y : incr) {
            pq.push(y);
        }
    }

    cout << result;
}