#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define vec vector

int N, M;
vec<ll> rowS;
vec<vec<vec<ll>>> colS;


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

    
}