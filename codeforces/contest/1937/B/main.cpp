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
        vector<array<bool, 2>> v(N);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < N; j++) {
                char c;
                cin >> c;
                v[j][i] = c == '1';
            }
        }
        
        queue<array<int, 2>> q;
        q.push({0, 0, 0});
    };
}