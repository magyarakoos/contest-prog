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
        int N;
        cin >> N;
        vector<int> v(N);
        cinv(v);

        if (v[0] != v[N - 1]) {
            int left = 0, right = 0;

            int i = 1, j = N - 2;
            while (i < N && v[i] == v[i - 1]) i++;
            while (j >= 0)
        }
    }
}