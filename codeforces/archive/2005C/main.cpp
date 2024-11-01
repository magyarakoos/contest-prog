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

    auto score = [&](int i) -> array<int, 3> {
        array<int, 3> result = {0, 0, 0};
        for (char c : a[i]) {
            int pos = NAREK.find(c);
            if (pos != NAREK.npos) {
                if (result[1] == pos) {
                    result[0]++;
                    result[0] %= 5;
                    result[1]++;
                } else {
                    result[2]++;
                }
            }
        }
        return result;
    };

    vector<array<array<int, 3>, 2>> dp(N);
    dp[0][0] = {0, 0, 0};
    dp[0][1] = score(0);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
