#include <bits/stdc++.h>
#ifdef LOCAL
#include <magyarakoos-debug.h>
#else
#define DB(...)
#endif

using namespace std;
using ll = long long;

const ll MAXN = 2e5, MOD = 1e9 + 7, INF = 1e18;

int f(string a, string b) {
    int j = 0;
    for (int i = 0; j < b.size() && i < a.size(); i++) {
        if (a[i] == b[j]) j++;
    }
    return j;
}

void solve() {
    string a, b;
    cin >> a >> b;
    int result = INT_MAX;
    for (int i = 0; i < b.size(); i++) {
        result = min(result, int(a.size() + b.size()) - f(a, b.substr(i)));
    }
    cout << result << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
