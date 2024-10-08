// O(N)
#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> v(N);
    for (int& x : v) cin >> x;

    int min_height = v[0], max_height = v[0], min_height_pos = 0, max_height_pos = 0,
        result_i = 0, result_len = 1, l = 0, r = 1;
    
    while (r < N) {

        if (abs(v[r] - v[r - 1]) > 1) {
            l = r;
            min_height = max_height = v[r];
            min_height_pos = max_height_pos = r;
            r++;
            continue;
        }

        bool smoller = v[r - 1] > v[r] && min_height > v[r],
              bigger = v[r - 1] < v[r] && max_height < v[r];

        if (min_height != max_height && (bigger || smoller)) {

            if (bigger) {
                l = min_height_pos + 1;
                min_height = max_height;
                min_height_pos = max_height_pos;
                max_height = v[r];
                max_height_pos = r;
            } else {
                l = max_height_pos + 1;
                max_height = min_height;
                max_height_pos = min_height_pos;
                min_height = v[r];
                min_height_pos = r;
            }
        } else {
            if (min_height >= v[r]) {
                min_height = v[r];
                min_height_pos = r;
            }
            if (max_height <= v[r]) {
                max_height = v[r];
                max_height_pos = r;
            }
            if (result_len < r - l + 1) {
                result_len = r - l + 1;
                result_i = l;
            }
        }
        r++;
    }

    cout << result_len << " " << result_i + 1;
}
