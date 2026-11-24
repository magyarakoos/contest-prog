#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    string s;
    cin >> n >> s;
    auto start = [](string str) -> int {
        bool a_found = 0, b_found = 0, c_found = 0;
        for (int i = 0; i < str.size(); i++) {
            a_found |= str[i] == 'A';
            b_found |= str[i] == 'B';
            c_found |= str[i] == 'C';
            if (a_found && b_found && c_found) {
                return i + 1;
            }
        }
        return -1;
    };

    for (int i = 0; i < 2; i++) {
        int si = start(s);
        if (si == -1) {
            cout << "0\n";
            return 0;
        }
        s = s.substr(si);
        reverse(s.begin(), s.end());
    }
    cout << s << "\n";

    n = s.size();
    vector<int> pa(n + 1), pb(n + 1), pc(n + 1);
    for (int i = 1; i <= n; i++) {
        pa[i] = pa[i - 1] + (s[i - 1] == 'A');
        pb[i] = pb[i - 1] + (s[i - 1] == 'B');
        pc[i] = pc[i - 1] + (s[i - 1] == 'C');
    }

    if (start(s) == -1) {
        cout << "0\n";
        return 0;
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        int l = i - 1, r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (pa[m + 1] - pa[i] >= 0 &&
                pb[m + 1] - pb[i] >= 0 &&
                pc[m + 1] - pc[i] >= 0) {
                r = m;
            } else {
                l = m;
            }
        }
        cout << i << " " << l << "\n";
    }
}
