#include <bits/stdc++.h>
#include <debug.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<string> a(N);
    for (string& s : a) cin >> s;
    sort(a.begin(), a.end(),
         [](const string& s, const string& t) { return s + t > t + s; });

    // dp[i][j] = az első `i` string értelmezési tartományában,
    // `j` string felhasználásával az optimális megoldás
    // lépések:
    // dp[i][j] = min(dp[i + 1][j], a[i] + dp[i + 1][j - 1]);
    vector dp(K, vector<string>(K));

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {}
    }
}
