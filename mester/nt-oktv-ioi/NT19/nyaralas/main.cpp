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

    int N, F;
    cin >> N >> F;

    vector<int> v(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }

    array<int, 3> result {0, 0, 0};

    for (int i = 1; i <= N; i++) {
        int left = 1, right = N;

        while (left < right) {
            if (left == i) {
                left++;
                continue;
            }
            if (right == i) {
                right--;
                continue;
            }

            if (v[left] + v[right] > F - v[i]) {
                right--;
                continue;
            }

            if (v[result[0]] + v[result[1]] + v[result[2]] < v[i] + v[left] + v[right]) {
                result = {i, left, right};
                if (v[i] + v[left] + v[right] == F) {
                    goto end;
                }
            }

            if (v[left] + v[right] < F - v[i]) {
                left++;
            }
        }
    }

    end:
    sort(all(result));
    cout << result[0] << ' ' << result[1] << ' ' << result[2] << '\n';
}