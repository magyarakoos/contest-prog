#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> v(N);
        cinv(v);

        int best = 1;

        if (v[0] != v[N - 1]) {
            int left = 0, right = 0;

            int c1 = v[0], c2 = v[N - 1];

            int i = 0, j = N - 1;
            while (i < N && v[i] == c1) {
                left++;
                i++;
            }
            while (j >= 0 && v[j] == c2) {
                right++;
                j--;
            }

            best = max({best, left, right});
        } else {
            int control = v[0];

            int result = 0;

            int i = 0, j = N - 1;
            while (i < j) {
                if (v[i] == control) {
                    i++;
                    result++;
                } 
                else if (v[j] == control) {
                    j--;
                    result++;
                }
                else {
                    break;
                }
            }

            best = max(best, result);
        }

        cout << N - best << '\n';
    }
}