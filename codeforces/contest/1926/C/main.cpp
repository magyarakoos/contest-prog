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

        if () 

        int result = 0;

        for (int i = 1; i <= N; i++) {

            if (!v[i]) {
                int j = i;

                while (j) {
                    v[i] += j % 10;
                    j /= 10;
                }
            }

            v[i] = result;
        }

        cout << result << '\n';
    }
}