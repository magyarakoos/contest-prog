#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;
using point = array<int, 2>;

int main() {
    speed;

    int N, K;
    cin >> N >> K;
    vector<int> v(N);
    cinv(v);

    if (N <= K + 1) {
        cout << max_element(all(v)) - v.begin() + 1;
        exit(0);
    }

    deque<point> q;
    
    for (int i = 0; i < K + 1; i++) {

        while (!q.empty() && q.back()[0] < v[i]) {
            q.pop_back();
        }

        q.push_back({v[i], i});
    }

    if (q.front()[0] == v[0]) {
        cout << 1;
        exit(0);
    }

    int bagoly = 1, left = 1 - K, right = 1 + K;

    while (bagoly < N) {

        if (!q.empty() && q.front()[1] < left) {
            q.pop_front();
        }

        if (right < N) {
            while (!q.empty() && q.back()[0] < v[right]) {
                q.pop_back();
            }

            q.push_back({v[right], right});
        }

        if (!q.empty() && q.front()[0] == v[bagoly]) {
            cout << bagoly + 1;
            exit(0);
        }

        left++;
        bagoly++;
        right++;
    }

    cout << -1;
}
