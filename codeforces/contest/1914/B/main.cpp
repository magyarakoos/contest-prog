#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()
#define has(s, e) s.count(e)

#define max_index(v) max_element(all(v)) - v.begin()
#define min_index(v) min_element(all(v)) - v.begin()
#define smax(x, y) x = max(x, y)
#define smin(x, y) x = min(x, y)

using namespace std;
using ll = long long;
using point = array<int, 2>;

int max(point p) { return max(p[0], p[1]); }
int min(point p) { return min(p[0], p[1]); }

int main() {
    speed;

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        int i = N - K;
        for (int j = 0; j <= K; j++) {
            cout << i++ << ' ';
        }
        i = N - K - 1;
        while (i) {
            cout << i-- << ' ';
        }
        cout << '\n';
    }
}