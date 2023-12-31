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

    int N, x;
    cin >> N >> x;
    vector<bool> al(N), am(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        al[i] = x <= a;
        am[i] = x < a;
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
        result += am[i];
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            result += al[i];
        }
    }

    cout << result;
}
