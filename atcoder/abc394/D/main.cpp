#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    string s;
    cin >> s;
    stack<char> st;
    auto ok = [&](char c) {
        if (c == ')') return st.top() == '(';
        if (c == ']') return st.top() == '[';
        return st.top() == '<';
    };
    for (char c : s) {
        if (c == '(' || c == '[' || c == '<') {
            st.push(c);
        } else {
            if (st.empty() || !ok(c)) {
                cout << "No\n";
                return;
            }
            st.pop();
        }
    }
    cout << (st.empty() ? "Yes" : "No") << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
