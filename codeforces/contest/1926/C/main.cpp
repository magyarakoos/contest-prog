#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    unordered_map<int, int> m;

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        int result = 0;

        for (int i = 1; i <= N; i++) {

            if (m.count(i)) {
                result += m[i];
            } else {
                int j = i;
                int k = 0;

                while (j) {
                    k += j % 10;
                    j /= 10;
                }

                m[i] = k;
                result += k;
            }
        }

        cout << result << '\n';
    }
}