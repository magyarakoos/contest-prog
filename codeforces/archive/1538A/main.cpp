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

    cout << '\n';
    int T;
    cin >> T;
    while (T--) {
        int N, result = 0;
        cin >> N;
        deque<int> v(N);
        cinv(v);

        auto [mn, mx] = minmax_element(all(v));
        int mni = mn - v.begin(), mxi = mx - v.begin(),
            mndist = N - mni - 1, mxdist = N - mxi - 1;

        if (min(mni, mndist) < min(mxi, mxdist)) {
            if (mni < mndist) {
                for (int i = 0; i <= mni; i++) {
                    v.pop_front();
                    result++;
                }
            } else {
                for (int i = 0; i <= mndist; i++) {
                    v.pop_back();
                    result++;
                }
            }

            N = v.size();
            mxi = max_element(all(v)) - v.begin();
            mxdist = N - mxi - 1;

            if (mxi < mxdist) {
                for (int i = 0; i <= mxi; i++) {
                    v.pop_front();
                    result++;
                }
            } else {
                for (int i = 0; i <= mxdist; i++) {
                    v.pop_back();
                    result++;
                }
            }
        } else {
            if (mxi < mxdist) {
                for (int i = 0; i <= mxi; i++) {
                    v.pop_front();
                    result++;
                }
            } else {
                for (int i = 0; i <= mxdist; i++) {
                    v.pop_back();
                    result++;
                }
            }

            N = v.size();
            mni = min_element(all(v)) - v.begin();
            mndist = N - mni - 1;
            
            if (mni < mndist) {
                for (int i = 0; i <= mni; i++) {
                    v.pop_front();
                    result++;
                }
            } else {
                for (int i = 0; i <= mndist; i++) {
                    v.pop_back();
                    result++;
                }
            }
        }

        cout << result << '\n';
    }
}
