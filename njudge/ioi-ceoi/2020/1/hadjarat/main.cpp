#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> R(N + 1), A(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> R[i] >> A[i];
    }

    vector<int> dp(N + 1, 1), prev(N + 1, -1);

    set<array<int, 4>> s;

    for (int i = 1; i <= N; i++) {
        for (auto it = s.end();; it--) {
            if (it == s.end()) it--;

            auto [_dp, _r, _a, _j] = *it;

            if (R[j] < R[i] && A[j] < A[i]) {
                dp[i] = _dp + 1;
                prev[i] = j;
                break;
            }

            if (it == s.begin()) break;
        }
        s.insert({dp[i], R[i], A[i]});
    }

    int mxi = max_element(all(dp)) - dp.begin();

    cout << dp[mxi] << "\n";

    stack<int> path;

    while (mxi != -1) {
        path.push(mxi);
        mxi = prev[mxi];
    }

    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
    cout << "\n";
}