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

    vector<ll> neg, pos;
    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        if (x < 0) {
            neg.push_back(x);
        } else {
            pos.push_back(x);
        }
    }

    if (neg.size() < B) {
        cout << "-1\n";
        exit(0);
    }

    ll result = 1;
    for (int i = 0; i < B; i++) {
        result *= -neg[i];
        result %= MOD;
    }
    for (int i = B; i < neg.size(); i++) { K += neg[i]; }

    if (K < 0) {
        cout << "-1\n";
        exit(0);
    }
}

