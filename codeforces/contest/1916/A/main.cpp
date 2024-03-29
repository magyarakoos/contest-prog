#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;
using point = array<int, 2>;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K, mul = 1;
        cin >> N >> K;
        while (N--) {
            int a;
            cin >> a;
            mul *= a;
        }

        if (2023 % mul) {
            cout << "NO\n";
        } else {
            cout << "YES\n" << 2023 / mul;
            K--;
            while (K--) {
                cout << " 1";
            }
            cout << '\n';
        }
    }
}
