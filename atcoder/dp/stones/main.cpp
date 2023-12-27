#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;
using point = array<int, 2>;

int main() {
    speed;

    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    cinv(a);

    vector<bool> dp(K + 1);

    for (int i = 0, j; i <= K; i++) {
        for (int n : a) {
            if (n <= i && !dp[i - n]) {
                dp[i] = 1;
                break;
            }
        }
    }
    
    cout << (dp[K] ? "First" : "Second");
}
