#include <bits/stdc++.h>

#pragma region Utility

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

#define sum(v) accumulate(all(v), 0)
#define product(v, T) accumulate(all(v), 1, multiplies<T>())

using namespace std;
using ll = long long;
using point = array<int, 2>;

int max(point p) { return max(p[0], p[1]); }
int min(point p) { return min(p[0], p[1]); }

template <typename T>
vector<T> prefix_sum(const vector<T>& v) {
    vector<T> result(size(v));
    partial_sum(all(v), result.begin());
    return result;
}

#pragma endregion

int main() {
    speed;

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<bool> u(N), v(N);

        for (int i = 0; i < N; i++) {
            char c;
            cin >> c;
            u[i] = c == '1';
        }

        for (int i = 0; i < N; i++) {
            char c;
            cin >> c;
            v[i] = c == '1';
        }

        int zoc = 0, ozc = 0;

        for (int i = 0; i < N; i++) {
            zoc += (!u[i] && v[i]);
            ozc += (u[i] && !v[i]); 
        }

        cout << max(zoc, ozc) << '\n';
    }
}