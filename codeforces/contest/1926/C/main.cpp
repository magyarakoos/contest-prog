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

        int result = 0;

        for (int i = 1; i <= N; i++) {

            int j = i;

            while (j) {
                result += j % 10;
                j /= 10;
            }
        }

        cout << result << '\n';
    }
}