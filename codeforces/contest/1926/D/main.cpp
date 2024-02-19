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

        vector<int> v(N);
        unordered_set<int> s;
        
        for (int i = 0; i < N; i++) {
            int X;
            cin >> X;
            v[i] = X;
            s.insert(X);
        }

        int result = N;

        for (int i = 0; i < N; i++) {
            int flip = ~v[i];

            if (s.count(flip)) {
                result--;
            }
        }

        cout << result << '\n';
    }
}