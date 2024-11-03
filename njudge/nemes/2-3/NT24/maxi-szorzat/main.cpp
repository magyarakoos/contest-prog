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
        int x;
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

    sort(neg.rbegin(), neg.rend());
    ll result = 1;
    for (int i = 0; i < B; i++) {
        result *= neg.back();
        result %= MOD;
        neg.pop_back();
    }

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < pos.size(); i++) {
        pq.push(pos[i]);
    }
    for (int i = 0; i < neg.size(); i++) {
        pq.push(neg[i]);
    }

    if (!pq.empty()) {
        for (int i = 0; i < K; i++) {
            int mn = pq.top();
            pq.pop();
            pq.push(mn + 1);
        }

        if (pq.top() < 0) {
            cout << "-1\n";
            exit(0);
        }

        while (!pq.empty()) {
            int mn = pq.top();
            pq.pop();
            result *= mn;
            result %= MOD;
        }
    }

    cout << result << "\n";
}

