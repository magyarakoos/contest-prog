#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

int f(const vector<int>& b) {
    deque<pair<bool, int>> a;
    deque<int> ones;
    for (int i = 0; i < b.size(); i++) {
        a.push_back({b[i], i});
        if (b[i]) ones.push_back(i);
    }
    int result = 0;
    while (!a.empty()) {
        if (a.front().first) {
            a.pop_front();
            ones.pop_front();
            result++;
        } else if (a.back().first) {
            a.pop_back();
            ones.pop_back();
            result++;
        } else if (ones.empty()) {
            break;
        } else {
            int d1 = ones.front() - a.front().second;
            int d2 = a.back().second - ones.back();
            if (d1 < d2) {
                a.pop_front();
            } else {
                a.pop_back();
            }
            result += 2;
        }
    }
    return result;
}

#define cases 1
void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int& x : b) {
        char c;
        cin >> c;
        x = c == '1';
    }
    int result = f(b);
    for (int& x : b) x ^= 1;
    cout << min(result, f(b)) << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
