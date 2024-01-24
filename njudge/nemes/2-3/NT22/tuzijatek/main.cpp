
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
    #ifdef ONLINE_JUDGE
    speed;
    #else
    #define cin fin
    ifstream fin("input.txt");
    #endif

    int N, S, T;
    cin >> N >> S >> T;
    vector<int> input(N + 1);
    for (int i = 1; i <= N; i++) cin >> input[i];
    vector<int> result({S});
    int left = S, right = S;
    for (int i = S; i <= N; i++) {
        if (abs(input[right] - input[i]) >= T) {
            result.push_back(i);
            right = i;
        }
    }
    for (int i = S; i > 0; i--) {
        if (abs(input[left] - input[i]) >= T) {
            result.push_back(i);
            left = i;
        }
    }
    sort(all(result));
    cout << size(result) << '\n';
    for (int x : result) cout << x << ' ';
}