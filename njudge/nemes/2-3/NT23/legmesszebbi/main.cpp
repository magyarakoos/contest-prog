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

    int N;
    cin >> N;
    vector<int> v(N);
    cinv(v);

    for (int w = N; w > 0; w--) {
        for (int i = 0, j = w - 1; j < N; i++, j++) {
            if (v[i] > v[j]) {
                cout << i + 1 << ' ' << j + 1;
                exit(0);
            }
        }
    }

    cout << -1;
}
