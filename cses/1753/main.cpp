#include <bits/stdc++.h>
using namespace std;
#define int int64_t

vector<int> z(const string& s) {}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    string s, t;
    cin >> s >> t;
    auto a = z(t + "#" + s);
    cout << count(a.begin(), a.end(), t.size()) << "\n";
}
