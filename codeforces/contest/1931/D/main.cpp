#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        int N, X, Y;
        cin >> N >> X >> Y;

        vector<int> v(N);
        cinv(v);

        unordered_map<int, set<int>> mx, my;

        ll result = 0;

        for (int i = 0; i < N; i++) {
            int modx = v[i] % X,
                mody = v[i] % Y;

            // a - b = 0
            // b = mody
            // a - mody = 0
            // a = mody

            if (mx.count(X - modx) && my.count(mody)) {
                vector<int> v(min(size(mx[X - modx]), size(my[mody])));

                auto it = set_intersection(all(mx[X - modx]), all(my[mody]), v.begin());

                for (auto st = v.begin(); st != it; st++) {
                    result++;
                }
            }

            mx[modx].insert(i);
            my[mody].insert(i);
        }
    }
}