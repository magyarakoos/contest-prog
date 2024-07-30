#include <bits/stdc++.h>
#ifdef LOCAL
#include <magyarakoos-debug.h>
#else
#define DB(...)
#endif

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int N;
    string s;
    cin >> N >> s;
    ll result = 0;
    stack<int> st;
    for (int i = 0; i < N; i++) {
        if (s[i] == '(') {
            st.push(i);
        }
        if (s[i] == ')') {
            assert(!st.empty());
            result += i - st.top();
            st.pop();
        }
        if (s[i] == '_') {
            if (!st.empty()) {
                result += i - st.top();
                st.pop();
            } else {
                st.push(i);
            }
        }
    }
    assert(st.empty());
    cout << result << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
