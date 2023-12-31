#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;
using point = array<int, 2>;

vector<int> factorize(int n) {
    vector<int> factors;
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    return factors;
}

int main() {
    speed;

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> v(N);
        cinv(v);

        double rem = 2023.0 / (double)accumulate(all(v), 1, multiplies<int>());

        if ((int)rem != rem) {
            cout << "NO\n";
        } else {
            vector<int> facts = factorize((int)rem);

            if (facts.size() > K) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
                for (int fact : facts) cout << fact << ' ';
                for (int i = 0; i < K - facts.size(); i++) {
                    cout << "1 ";
                }
                cout << '\n';
            }
        }

    }
}
