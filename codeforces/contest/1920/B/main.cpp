#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        int N, K, X;
        cin >> N >> K >> X;

        vector<int> v(N);
        for (int& x : v) cin >> x;

        sort(v.rbegin(), v.rend());

        for (int i = 1; i < N; i++) {
            v[i] += v[i - 1];
        }

        int mx = INT_MIN;

        for (int i = 0; i <= K; i++) {
            mx = max(
                mx, 
                // get the total sum
                // add the negative of all the values in the range [0, i + X] (Bob negates)
                // add the values back in what you didn't actually negate, but only remove (Alice removes)
                v[N - 1] - 2 * v[min(N, i + X) - 1] + (i ? v[i - 1] : 0)
            );
        }
        
        cout << mx << '\n';
    }
}