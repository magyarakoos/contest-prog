#include <bits/stdc++.h>
using namespace std;

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
        cout << upper_bound(v.begin(), v.end(), M) - v.begin() << "\n";
    }
}