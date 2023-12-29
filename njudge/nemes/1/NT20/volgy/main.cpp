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

    int N;
    cin >> N;


    vector<int> T(N);
    cinv(T);

    if (N < 3) {
        cout << -1;
        exit(0);
    }
    
    int max_l = 1;

    for (int i = 0; i < N; i++) {
        int max_h = 0;
        for (int j = i + 1; j < N - 1; j++) {
            if (T[i] <= T[j]) break;
            max_h = max(max_h, T[j]);
            if (max_h < T[j + 1]) {
                max_l = max(max_l, j + 1 - i);
            }
        }
    }

    cout << (max_l == 1 ? -1 : max_l);
}
