#include <bits/stdc++.h>
using namespace std;

struct Tr { map<char, Tr*> to; };

void solve() {
    Tr* root = new Tr();
    string s;
    cin >> s;
    int n = s.size(), result = 0;
    for (int i = n - 1; ~i; i--) {
        Tr* cur = root;
        for (int j = i; j < n; j++) {
            Tr*& v = cur->to[s[j]];
            if (!v) {
                v = new Tr();
                result++;
            }
            cur = v;
        }
    }
    cout << result << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) solve();
}
