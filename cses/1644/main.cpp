#include <array>
#include <climits>
#include <deque>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

vector<ll> sliding_min(const vector<ll>& a, int N, int K) {
    vector<ll> result;
    deque<array<ll, 2>> dq;

    for (int i = 0; i < N; i++) {
        while (!dq.empty() && dq.front()[1] <= i - K) dq.pop_front();
        while (!dq.empty() && dq.back()[0]  >=  a[i]) dq.pop_back();

        dq.push_back({a[i], i});
        result.push_back(dq.front()[0]);
    }

    return result;
}

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<ll> a(N), ps(N + 1);
    for (ll& x : a) cin >> x;

    partial_sum(a.begin(), a.end(), ps.begin() + 1);


    vector<ll> slmn = sliding_min(ps, N, B - A + 1);

    ll result = INT_MIN;

    for (int i = A - 1; i < N; i++) {
        result = max(result, ps[i + 1] - slmn[i - A + 1]);
    }

    cout << result << "\n";
}
