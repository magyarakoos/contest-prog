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

        unordered_map<int, int> mx, my;

        for (int i = 0; i < N; i++) {
            int modx = v[i] % X,
                mody = v[i] % Y;

            int targetx = X - modx;

            // a - b = 0
            // b = mody
            // a - mody = 0
            // a = mody

            if (mx.count(X - modx) && my.count(targety)) {

            }

            mx[modx] = i + 1;
            my[mody] = i + 1;
        }
    }
}