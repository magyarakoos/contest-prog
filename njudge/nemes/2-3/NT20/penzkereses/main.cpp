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

    int N, P;
    cin >> N >> P;
    vector<int> v(N);
    cinv(v);

    int result = INT_MAX, sum = v[0];

    for (int l = 0, r = 0; r < N; r++) {
        while (sum < P && l < r - 1) {
            sum -= v[l];
            l++;
        }

        if (sum >= P) {
            result = min(result, r - l + 1);
        }

        if (r < N) {
            sum += v[r];
        }
    }

    cout << result;
}
