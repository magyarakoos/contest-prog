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

    ll avg = accumulate(p.begin(), p.end(), 0LL),
       goal = K * N;

    if (avg == goal) {
        cout << "0\n";
        exit(0);
    }

    if (avg < goal) {
        cout << "1\n";
        exit(0);
    }

    for (int i = 0; i < N; i++) {
        avg -= p[i] - 1;
        if (avg <= goal) {
            cout << i + 1 << "\n";
            exit(0);
        }
    }
}
