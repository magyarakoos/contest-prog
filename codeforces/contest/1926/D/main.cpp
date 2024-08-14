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

        unordered_multiset<unsigned> m;

        int result = 0;

        for (int i = 0; i < N; i++) {
            unsigned X;
            cin >> X;

            unsigned Y = ~X & (UINT_MAX >> 1);

            auto it = m.find(Y);

            if (it != m.end()) {
                result++;
                m.erase(it);
            } else {
                m.insert(X);
            }
        }

        cout << size(m) + result << '\n';
    }
}
