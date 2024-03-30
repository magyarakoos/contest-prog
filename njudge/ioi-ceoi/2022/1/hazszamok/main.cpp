#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int K;
    cin >> K;
    vector<ll> v(K);
    ll mn = 1e12 + 1;
    for (int i = 0; i < K; i++) {
        cin >> v[i];
        mn = min(mn, v[i]);
    }

    int iter = 1;
    ll curr = K;
    while ((curr - 1) * K <= mn) {
        iter++;
        curr *= K;
    }

    

    cerr << iter << "\n";
}