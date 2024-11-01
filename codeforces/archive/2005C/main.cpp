#include <array>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<string> a(N);
    for (string& s : a) cin >> s;

    vector<array<array<int, 3>, 2>> dp(N);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
