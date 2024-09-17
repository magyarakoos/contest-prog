#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll INF = 1e18;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> a(N + 1);
    for (int i = 1; i <= N; i++) cin >> a[i];

    vector<array<ll, 2>> dp(N + 1);
    dp[0] = {0, -INF};
}
