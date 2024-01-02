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
        int N;
        cin >> N;
        ll sum = 0;
        while (N--) {
            int a;
            cin >> a;
            sum += a;
        }
        double rt = sqrt(sum);
        cout << (rt == (int)rt ? "YES" : "NO") << '\n';
    }
}
