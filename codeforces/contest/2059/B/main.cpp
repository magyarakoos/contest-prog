#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N + 1), ps(N + 1);
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) {
        ps[i] = ps[i - 1] + (A[i] != 1);
    }
    int result = N / 2 + 1;
    int j = N - K + 3;
    for (int i = j + 1; i <= N; i += 2) {
        if (A[i] != (i - (j + 1)) / 2 + 2) {
            result = min(result, (i - (j + 1)) / 2 + 2);
            break;
        }
    }
    set<int> s, os;
    int ocnt = 0;
    for (int i = 1; i < j; i++) {
        if (A[i] != 1)
            s.insert(i);
        else
            os.insert(i);
    }
    for (int i = 1; i + 1 < j; i++) {
        s.erase(i);
        os.erase(i);
        int curr = j - i - 1;
        if (curr > 0) {
            if (!s.empty()) {
                result = min(result, *s.begin() - i);
            } else if (os.size() >= 2) {
                int k = *os.begin();
                os.erase(k);
                result = min(result, *os.begin() - i);
                os.insert(k);
            }
        }
    }
    cout << result << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
