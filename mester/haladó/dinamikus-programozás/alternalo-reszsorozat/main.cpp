#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

constexpr int INF = 1e9;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<int> v(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }

    // dp[i][0]/dp[i][1] = max részsorozat, ha v[i] a sorozat vége és nagyobb/kisebb mint a szomszédja
    vector<array<int, 2>> dp(N + 1, {1, 1}), prev(N + 1, {-1, -1});

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            
            if (v[i] < v[j]) {
                if (dp[i][0] < dp[j][1] + 1) {
                    dp[i][0] = dp[j][1] + 1;
                    prev[i][0] = j;
                }
            }
            else if (v[i] > v[j]) {
                if (dp[i][1] < dp[j][0] + 1) {
                    dp[i][1] = dp[j][0] + 1;
                    prev[i][1] = j;
                }
            }
        }
    }

    int curr = 0;
    bool high = 0;

    for (int i = 1; i <= N; i++) {
        if (dp[curr][high] < dp[i][0]) {
            curr = i;
            high = 0;
        }
        if (dp[curr][high] < dp[i][1]) {
            curr = i;
            high = 1;
        }
    }

    cout << dp[curr][high] << '\n';

    deque<int> path;

    do {
        path.push_front(curr);
        curr = prev[curr][high];
        high ^= 1;
    } while (curr != -1);

    for (int x : path) cout << x << ' ';
    cout << '\n';
}