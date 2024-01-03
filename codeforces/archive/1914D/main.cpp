#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;
using point = array<int, 2>;

array<int, 3> max3i(const vector<int>& v) {
    array<int, 3> result = {-1, -1, -1};
    for (int i = 0; i < v.size(); i++) {
        if (result[2] == -1 || v[result[2]] < v[i]) {
            result[0] = result[1];
            result[1] = result[2];
            result[2] = i;
        } else if (result[1] == -1 || v[result[1]] < v[i]) {
            result[0] = result[1];
            result[1] = i;
        } else if (result[0] == -1 || v[result[0]] < v[i]) {
            result[0] = i;
        }
    }
    return result;
}

int main() {
    speed;

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> a(N), b(N), c(N);
        cinv(a); cinv(b); cinv(c);

        int result = 0;
        for (int i : max3i(a)) {
            for (int j : max3i(b)) {
                for (int k : max3i(c)) {
                    if (i != j && j != k && i != k) {
                        result = max(result, a[i] + b[j] + c[k]);
                    }
                }
            }
        }
         
        cout << result << '\n';
    }
}
