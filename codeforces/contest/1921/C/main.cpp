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
        ll N, F, A, B;
        cin >> N >> F >> A >> B;
        vector<ll> v(N);
        cinv(v);

        vector<ll> diffS(N);
        diffS[0] = v[0];

        for (int i = 1; i < N; i++) {
            diffS[i] = v[i] - v[i - 1];
        }
        
        int i;
        for (i = 0; i < N; i++) {
            F -= min(A * diffS[i], B);

            if (F < 1) {
                break;
            }
        }

        cout << (i == N ? "YES" : "NO") << '\n';
    }
}