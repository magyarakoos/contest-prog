#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;
using point = array<int, 2>;

int main() {
    speed;

    int T;
    cin >> T;
    while (T--) {
        int N, oc = 0, tc = 0;
        cin >> N;
        while (N--) {
            int a;
            cin >> a;
            (a == 1 ? oc : tc)++;
        }

        if ((tc % 2 == 0 && oc % 2 == 0) || (tc % 2 != 0 && oc > 0 && oc % 2 == 0)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}
