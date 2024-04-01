#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

struct Cmp {
    bool operator()()
};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> R(N + 1), A(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> R[i] >> A[i];
    }

    vector<int> dp(N + 1, 1), prev(N + 1, -1);

    priority_queue<array<int, 3>, vector<array<int, 3>>, Cmp> pq;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (R[j] < R[i] && A[j] < A[i]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }
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