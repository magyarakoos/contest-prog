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

    if (B > neg.size()) {
        cout << "-1\n";
        exit(0);
    }

    // This fucking edge case: only B negatives (you have to
    // use all K increments)
    if (B == neg.size() && pq.empty()) {}

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

    while (K--) {
        ll mn = pq.top();
        pq.pop();
        pq.push((mn + 1) % MOD);
    }

    while (!pq.empty()) {
        ll mn = pq.top();
        pq.pop();
        result *= mn;
        result %= MOD;
    }

    cout << result << "\n";
}

