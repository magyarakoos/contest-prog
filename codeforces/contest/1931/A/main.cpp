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
            N--;
        } else {
            cout << (char)(first + 'a');
            N -= first;
        }

        int second = N - 26;
        if (second < 0) {
            cout << 'a';
            N--;
        } else {
            cout << (char)(second + 'a');
            N -= second;
        }

        cout << (char)(N + 'a') << '\n';

        cout << first << ' ' << second << ' ' << N << '\n';
    }
}