#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define vec vector

int N, M;
vec<ll> rowS;
vec<vec<vec<ll>>> colS;
ll res = LLONG_MAX;

void solve(vector<bool> painted) {
    if (painted.size() == N) {
        ll curr = 0;
        for (int i = 0; i < N; i++) {
            if (painted[i]) curr += rowS[i];
        }

        
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