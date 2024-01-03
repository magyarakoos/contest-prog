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
    vector<point> v(N);

    for (int i = 0; i < N; i++) cin >> v[i][0];
    for (int i = 0; i < N; i++) cin >> v[i][1];

    sort(all(v));

    ll t = 0, xp = 0;
    int l = 0, r = N - 1;
    while (l <= r) {
        if (v[l][0] <= xp) {
            // finish the remaining in one sitting (yum)
            t += v[l][1];
            xp += v[l][1];
            v[l] = {0, 0};
            l++;
        } else {
            // if had to finish the inefficient way, this is done (mining be boring aa hell)
            if (--v[r][1] == 0) r--;
            t += 2; // go one by one here, time and xp gain is constant
            xp++;
        }
    }

    cout << t;
}
