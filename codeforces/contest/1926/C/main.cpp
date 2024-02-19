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

        const vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9};

        cout << 46 * (N / 10) << ' ' << accumulate(v.begin(), v.begin() + (N % 10), 0) << '\n';
    }
}