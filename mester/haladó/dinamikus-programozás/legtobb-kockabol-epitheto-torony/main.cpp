#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<array<int, 3>> boxS(N); // {hossz, súly, sorszám}

    for (int i = 0; i < N; i++) {
        cin >> boxS[i][0] >> boxS[i][1];
        boxS[i][2] = i + 1;
    }

    sort(all(boxS));

    vector<int> dp(N, 1), prev(N); // dp[i] = max magasság, ha boxS[i] a torony legalja

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (boxS[j][1] <= boxS[i][1]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }
    }

    int i = max_element(all(dp)) - dp.begin();

    cout << dp[i] << '\n';

    vector<int> path;

    for (int j = dp[i]; j > 0; j--) {
        path.push_back(boxS[i][2]);
        i = prev[i];
    };

    for (int x : path) cout << x << ' ';
    cout << '\n';
}
