#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    vector<int> v(200'001);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<unsigned> v(N);
        unordered_map<unsigned, int> m;
        
        int result = N;

        for (int i = 0; i < N; i++) {
            unsigned X;
            cin >> X;
            v[i] = X;
            m[X]++;
        }


        for (int i = 0; i < N; i++) {
            unsigned flip = ~v[i] & (UINT_MAX >> 1);

            if (m[v[i]] && m[flip]) {
                cout << flip << ' ' << v[i] << '\n';
                result--;
                m[flip]--;
                m[v[i]]--;
            }
        }

        cout << result << '\n';
    }
}