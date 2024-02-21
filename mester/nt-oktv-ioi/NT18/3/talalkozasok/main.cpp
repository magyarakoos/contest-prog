#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<array<int, 2>> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i][0] >> v[i][1];
    }

    sort(all(v));

    int mx = 0, mxi = 0;

    for (int i = 0; i < N; i++) {
        int curr = 0;

        
    }
}