#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;
using point = array<int, 2>;

#define fc(s, c) s.find(c) != s.npos

int main() {
    speed;

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        string s;
        vector<bool> v(N);
        for (int i = 0; i < N; i++) {
            char c;
            cin >> c;
            v[i] = c == 'a' || c == 'e';
        }

        if (N == 1) {
            cout << s[0] << '\n';
            continue;
        }

        
    }
}
