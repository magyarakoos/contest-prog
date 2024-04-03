#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> v(N);
    for (int& x : v) cin >> x;

    int l = 0, r = 1, mx = -1, result = -1;
    while (r < N) {
        if (v[l] < v[r]) {
            if (mx < r - l) {
                mx = r - l;
                result = l + 1;
            }
            l = r;
        }
        r++;
    }

    cout << result;
}