#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;
using point = array<int, 2>;

#define fc(c) s.find(c) != s.npos

int main() {
    speed;

    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < 3; i++) {
            string s;
            cin >> s;
            bool a = fc('A'), b = fc('B'), c = fc('C');
            if (fc('?')) {
                cout << (a && b ? 'C' : a && c ? 'B' : 'A') << '\n';
            }
        }
    }
}
