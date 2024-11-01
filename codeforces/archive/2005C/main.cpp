#include <array>
#include <iostream>
#include <vector>

using namespace std;

const string NAREK = "narek";

void solve() {
    int N, M;
    cin >> N >> M;
    vector<string> a(N);
    for (string& s : a) cin >> s;

    auto score = [&](int i,
                     array<int, 3> curr) -> array<int, 3> {
        for (char c : a[i]) {
            int pos = NAREK.find(c);
            if (pos != NAREK.npos) {
                if (curr[1] == pos) {
                    curr[0]++;
                    curr[0] %= 5;
                    curr[1]++;
                } else {
                    curr[2]++;
                }
            }
        }
        return curr;
    };

    vector<array<array<int, 3>, 2>> dp(N);
    dp[0][0] = {0, 0, 0};
    dp[0][1] = score(0, {0, 0, 0});

    for (int i = 1; i < N; i++) {}
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
