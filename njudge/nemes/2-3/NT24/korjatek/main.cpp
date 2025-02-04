#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 2e5;

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> P(N), pos(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        P[i]--;
        pos[P[i]] = i;
    }

    auto d = [&](int i, int j) {
        return i <= j ? j - i : N + j - i;
    };

    int result = 0;
    for (int i = 0; i < N - 1; i++) {
        result += d(pos[i], pos[i + 1]);
    }

    cout << result << "\n";
}
