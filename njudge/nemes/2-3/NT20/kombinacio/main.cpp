#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    vector<int> v(M);
    for (int& x : v) cin >> x;
    vector<int> bef = v, aft = v;

    if (bef[M - 2] + 1 < bef[M - 1]) {
        bef[M - 1]--;
    }
}