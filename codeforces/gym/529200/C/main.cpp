#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, minw, minh;
    cin >> N >> minw >> minh;

    vector<array<int, 3>> cardS;

    for (int i = 1; i <= N; i++) {
        int w, h;
        cin >> w >> h;
        if (minw < w && minh < h) {
            cardS.push_back({w, h, i});
        }
    }

    if (cardS.empty()) {
        cout << 0;
        exit(0);
    }

    sort(cardS.begin(), cardS.end());

    N = cardS.size();

    vector<int> dp(N, 1), last(N, -1);

    int maxi = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (cardS[j][1] < cardS[i][1] && cardS[j][0] < cardS[i][0] &&
                dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                last[i] = j;

                if (dp[maxi] < dp[i]) {
                    maxi = i;
                }
            }
        }
    }

    cout << dp[maxi] << '\n';

    deque<int> path;

    do {
        path.push_front(cardS[maxi][2]);
        maxi = last[maxi];
    } while (maxi != -1);

    for (int x : path) cout << x << ' ';
    cout << '\n';
}
