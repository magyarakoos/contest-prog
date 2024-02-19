#include <bits/stdc++.h>

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

        vector<vector<bool>> v(N, vector<bool>(N));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                char c;
                cin >> c;
                v[i][j] = c == '1';
            }
        }

        for (int i = 1; i < N; i++) {
            for (int j = 1; j < N; j++) {
                
            }
        }
    }
}