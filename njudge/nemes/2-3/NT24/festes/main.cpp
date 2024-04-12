#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define vec vector
#define size(v) (int)v.size()

int N, M;
vec<ll> rowS;
vec<vec<vec<ll>>> colS;
ll res = LLONG_MAX;

void solve(vector<bool> painted) {
    if (size(painted) == N) {
        ll curr = 0;
        for (int i = 0; i < N; i++) {
            if (painted[i]) curr += rowS[i];
        }

        for (int i = 0; i < M; i++) {
            ll mn = LLONG_MAX;
            for (int j = 0; j < N; j++) {
                for (int k = j; k < N; k++) {
                    vector<bool> mask = painted;
                    for (int l = j; l <= k; l++) {
                        mask[l] = 1;
                    }
                    if (count(mask.begin(), mask.end(), 1) == N) {
                        mn = min(mn, colS[i][j][k]);
                    }
                }
            }
            curr += mn;
        }
        res = min(res, curr);
    } else {
        painted.push_back(0);
        solve(painted);
        painted.back() = 1;
        solve(painted);
        painted.pop_back();
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> N >> M;
    rowS.resize(N);
    colS.assign(M, vec<vec<ll>>(N, vec<ll>(N)));

    for (int i = 0; i < N; i++) {
        cin >> rowS[i];
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = j; k < N; k++) {
                cin >> colS[i][j][k];
            }
        }
    }

    solve({});
    cout << res;
}