#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
    ll N, K, B;
    cin >> N >> K >> B;

    vector<ll> neg;
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        if (x < 0) {
            neg.push_back(x);
        } else {
            pq.push(x);
        }
    }

    if (neg.size() < B) {
        cout << "-1\n";
        exit(0);
    }

    sort(neg.begin(), neg.end());
    ll result = 1;

    for (int i = 0; i < B; i++) {
        result *= -neg[i];
        result %= MOD;
    }

    for (int i = B; i < neg.size(); i++) {
        K += neg[i];
        pq.push(0);
    }

    if (K < 0) {
        cout << "-1\n";
        exit(0);
    }
}

