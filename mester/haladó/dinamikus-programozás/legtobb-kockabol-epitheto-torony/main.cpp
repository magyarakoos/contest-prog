#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()
#define smax(x, y) x = max(x, y)
#define smin(x, y) x = min(x, y)

using namespace std;
using ll = long long;

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

    for (int i = 0; i < N; i++) {
        cout << boxS[i][0] << ' ' << boxS[i][1] << ' ' << boxS[i][2] << '\n';
    } 

    vector<int> dp(N); // dp[i] = max magasság, ha boxS[i] a torony legalja
    dp[0] = 1; // a legkisebb kocka alá nem fér be semmi

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (boxS[j][1] <= boxS[i][1]) {
                smax(dp[i], dp[j] + 1);
            }
        }
    }

    cout << *max_element(all(dp)) << '\n';
}
