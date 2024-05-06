#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int& x : v) cin >> x;

    vector<int> result;
    vector<bool> dp(100'001);
    for (int i = 1; i <= N; i++) {
        for (int x : v) {
            if (i - x > 0 && dp[i - x]) {
                dp[i] = 1;
                result.push_back(i);
                break;
            }
        }
    }

    cout << result.size() << "\n";
    for (int x : result) cout << x << " ";
    cout << "\n";
}
