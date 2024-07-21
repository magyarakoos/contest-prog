#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    int N = s.size(), result = 1;
    vector<int> dp(N);
    dp[0] = 1;
    for (int i = 1; i < N; i++) {
        result = max(result, dp[i] = (s[i] == s[i - 1]) * dp[i - 1] + 1);
    }
    cout << result;
}
