#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int first(bool one, int i, int j, const vector<int>& v) {
    for (; i <= j; i++) {
        if (v[i] && one) {
            return i;
        }
        if (!v[i] && !one) {
            return i;
        }
    }

    return -1;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<int> v(N);
        for (int& e : v) cin >> e;
        
        for (int i = 0; i < N; i++) {
            int fo = first(1, i, N - 1, v);
            int fz = first(0, i, N - 1, v);

            
        }
    }
}