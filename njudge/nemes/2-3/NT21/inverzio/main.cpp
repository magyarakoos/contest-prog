#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<array<int, 2>> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i][0];
        a[i][1] = i;
    }
    sort(a.rbegin(), a.rend());
    int mx_j = -1, result_i = 1e9, result_j = -1;
    for (auto [x, i] : a) {
        if (result_j - result_i < mx_j - i) {
            result_i = i;
            result_j = mx_j;
        }
        mx_j = max(mx_j, i);
    }
    if (result_j - result_i > 0) {
        cout << result_i + 1 << " " << result_j + 1 << "\n";
    } else {
        cout << "-1\n";
    }
}
