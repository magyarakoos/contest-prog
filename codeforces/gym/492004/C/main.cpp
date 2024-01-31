#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<int> v(N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> v[i];
        }

        vector<int> dp(N + 1, 1);

        for (int i = 1; i <= N; i++) {
            for (int j = 2 * i; j <= N; j += i) {
                if (v[i] < v[j]) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        cout << *max_element(all(dp)) << '\n';
    }
}
