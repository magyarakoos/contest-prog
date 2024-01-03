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
            s += c;
        }

        if (N == 1) {
            cout << s << '\n';
            continue;
        }

        vector<string> partS;
        string t;

        for (int i = 0; i < N; i++) {
            if (i + 1 == N) {
                t += s[i];
            }

            else if (!v[i] && !v[i + 1]) {
                t += s[i];
                partS.push_back(t);
                t = "";
            }
            
            else if (!v[i] && v[i + 1]) {
                if (!t.empty()) partS.push_back(t);
                t = "";
                t += s[i];
                t += s[i + 1];
                if (i + 1 < N) i++;
            }

            else {
                t += s[i];
            }
        }

        if (!t.empty()) {
            partS.push_back(t);
        }

        for (int i = 0; i < partS.size(); i++) {
            cout << partS[i];
            if (i + 1 < partS.size()) cout << '.';
        }
        cout << '\n';
    }
}
