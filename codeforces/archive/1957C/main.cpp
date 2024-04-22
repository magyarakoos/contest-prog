#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;

    int M = N * N;
    while (K--) {
        int I, J;
        cin >> I >> K;
        M--;
        if (I != J) M--;
    }

    vector<int> dp(M + 1);
    dp[0] = 1;
    dp[1] = 1;

    
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}