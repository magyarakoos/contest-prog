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

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        
        vector<int> a(N), b(N);
        cinv(a);
        cinv(b);

        int max_score = 0, sum_a = 0, max_b = 0;
        
        for (int i = 0; i < min(N, K); i++) {
            sum_a += a[i];
            max_b = max(max_b, b[i]);

            int rounds_left = K - i - 1;

            max_score = max(max_score, sum_a + max_b * rounds_left);
        }

        cout << max_score << '\n';
    }
}
