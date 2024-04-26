#include <bits/stdc++.h>

int main() {
    speed;

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> v(N);
        cinv(v);

        int result = 0, la = INT_MAX, lb = INT_MAX;

        for (int i = 0; i < N; i++) {
            int mn = min(la, lb), mx = max(la, lb);

            if (v[i] <= mn) {
                mn = v[i];
            } else if (mx < v[i]) {
                result++;
                mn = v[i];
            } else {
                mx = v[i];
            }

            la = mn, lb = mx;
        }

        cout << result << '\n';
    }
}