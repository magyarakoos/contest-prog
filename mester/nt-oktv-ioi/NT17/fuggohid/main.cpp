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

    vector<int> Bal(N + 1), Jobb(N + 1);
    
    for (int i = 1; i <= N; i++) {
        cin >> Bal[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> Jobb[i];
    }

    vector<array<int, 2>> dp(N + 1);

    dp[1][0] = Bal[1];
    dp[1][1] = Jobb[1];

    for (int i = 2; i <= N; i++) {
        dp[i][0] = 
    }
}