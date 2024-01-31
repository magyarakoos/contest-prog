#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int K, N;
    cin >> K >> N;

    vector<array<int, 3>> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i][0] >> v[i][1];
        v[i][2] = i + 1;
    }

    sort(all(v), [](auto a, auto b){ return a[1] < b[1]; });

    int pos = 0;
    vector<int> result;

    while (pos < K) {

        int i = N - 1;
        for (; i >= 0; i--) {
            if (v[i][0] <= pos) {
                break;
            }
        }

        if (i == -1) {
            cout << 0;
            exit(0);
        }

        pos = v[i][1];
        result.push_back(v[i][2]);
    }

    cout << size(result) << '\n';
    for (int x : result) cout << x << ' ';
    cout << '\n';
}