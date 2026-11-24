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
}
