#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
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
        // 78 -> 26 26 26 -> 26 52
        int first = N - 52;
        if (first < 0) {
            cout << 'a';
        } else {
            cout << (char)(first + 'a');
        }
    }
}