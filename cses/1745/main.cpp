#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;

int main() {
    int N;
    cin >> N;
    vector<bool> dp(MAXN + 1);
    dp[0] = 1;

    while (N--) {
        int X;
        cin >> X;
        for (int i = MAXN; i >= X; i--) {
            if (dp[i - X]) dp[i] = 1;
        }
    }

    vector<int> result;
    for (int i = 1; i <= MAXN; i++) {
        if (dp[i]) result.push_back(i);
    }

    cout << result.size() << "\n";
    for (int x : result) cout << x << " ";
    cout << "\n";
}
