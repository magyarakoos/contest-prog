#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    vector<int> v(200'001);

    int biggest = 0;
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        if (N <= biggest) {
            cout << v[N] << '\n';
            continue;
        }

        int result = v[biggest];

        for (int i = biggest + 1; i <= N; i++) {

            if (!v[i]) {
                int j = i;

                while (j) {
                    v[i] += j % 10;
                    j /= 10;
                }
            }

            result += v[i];
        }

        cout << result << '\n';

        biggest = max(biggest, N);
    }
}