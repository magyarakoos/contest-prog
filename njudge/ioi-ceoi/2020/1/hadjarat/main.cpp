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

    vector<int> dp(N + 1, 1), prev(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (R[j] < R[i] && A[j] < A[i]) {
                if (dp[i] )
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << *max_element(all(dp));
}