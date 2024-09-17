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
    vector<int> a(N);
    for (int& x : a) cin >> x;

    vector<array<ll, 2>> dp(N);
    dp[0] = {a[0], -INF};

    for (int i = 1; i < N; i++) {}
}
