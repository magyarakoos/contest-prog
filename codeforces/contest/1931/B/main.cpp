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
        vector<ll> a(N);
        ll avg = 0;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            avg += a[i];
        }
        avg /= N;
        ll carry = 0;
        for (int i = 0; i < N; i++) {
            a[i] += carry;
            if (a[i] < avg) {
                cout << "NO\n";
                goto next;
            }

            carry = a[i] - avg;
        }

        cout << "YES\n";

        next:continue;
    }
}
