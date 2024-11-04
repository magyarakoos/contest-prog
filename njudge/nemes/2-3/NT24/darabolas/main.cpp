#include <array>
#include <iostream>
#include <queue>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    ll M, N, Mdb = 1, Ndb = 1;
    cin >> M >> N;

    priority_queue<array<ll, 2>> pq;

    for (int i = 0; i < M - 1; i++) {
        ll x;
        cin >> x;
        pq.push({0, x});
    }

    for (int i = 0; i < N - 1; i++) {
        ll x;
        cin >> x;
        pq.push({1, x});
    }

    ll result = 0;
    while (!pq.empty()) {
        auto [axis, value] = pq.top();
        pq.pop();
        if (axis) {
            result += value * Mdb;
            Ndb++;
        } else {
            result += value * Ndb;
            Mdb++;
        }
    }

    cout << result << "\n";
}
