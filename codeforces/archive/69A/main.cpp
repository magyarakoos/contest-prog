#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;
using point = array<int, 2>;

int N, x, y, z;
int main() {
    speed;

    cin >> N;
    while (N--) {
        int a, b, c;
        cin >> a >> b >> c;
        x += a; y += b; z += c;
    }

    cout << ((x | y | z) ? "NO" : "YES");
}
