#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

#define cases 0
void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for (int& x : P) cin >> x, x--;
    vector<int> Pm(N);
    for (int i = 0; i < N; i++) {
        Pm[P[i]] = i;
    }

    vector<int> sl_mx(N - K + 1);
    deque<int> dq;
    for (int i = 0; i < N; i++) {
        while (!dq.empty() && dq.front() + K <= i) dq.pop_front();
        while (!dq.empty() && Pm[dq.back()] <= Pm[i]) dq.pop_back();
        dq.push_back(i);
        if (i - K + 1 >= 0) {
            sl_mx[i - K + 1] = Pm[dq.front()];
        }
    }

    vector<int> sl_mn(N - K + 1);
    dq.clear();
    for (int i = 0; i < N; i++) {
        while (!dq.empty() && dq.front() + K <= i) dq.pop_front();
        while (!dq.empty() && Pm[dq.back()] >= Pm[i]) dq.pop_back();
        dq.push_back(i);
        if (i - K + 1 >= 0) {
            sl_mn[i - K + 1] = Pm[dq.front()];
        }
    }

    int res = INT_MAX;
    for (int i = 0; i < N - K + 1; i++) {
        smin(res, sl_mx[i] - sl_mn[i]);
    }
    cout << res;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
