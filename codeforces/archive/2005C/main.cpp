#include <array>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<string> a(N);
    for (string& s : a) cin >> s;

    auto score = [&](int i) -> array<int, 3> {

    };

    vector<array<array<int, 3>, 2>> dp(N);
    dp[0] = {{0, 0, 0}, score(0)};
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
