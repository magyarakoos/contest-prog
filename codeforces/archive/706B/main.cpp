#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> v(N);
    for (int& x : v) cin >> x;
    sort(v.begin(), v.end());
    int Q;
    while (Q--) {
        int M;
        cin >> M;
        auto it = upper_bound(v.begin(), v.end(), M);
        if (it == v.end()) {
            cout << N << "\n";
        } else {
            cout << i
        }
    }
}