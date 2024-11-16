#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

#define cases 0
void solve() {
    string S;
    cin >> S;
    vector<int> result;
    for (char c : S) {
        if (c == '|')
            result.push_back(0);
        else
            result.back()++;
    }
    result.pop_back();
    for (int x : result) cout << x << " ";
    cout << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
