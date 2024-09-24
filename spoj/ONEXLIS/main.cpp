#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int& x : a) cin >> x;

    vector<array<int, 2>> pr;
    vector<int> lis;
    int prmx = 0;

    for (int i = 0; i < N; i++) {
        auto it = upper_bound(lis.begin(), lis.end(), a[i]);
        if (it == lis.end()) {
            lis.push_back(a[i]);
            prmx = a[i];
        } else {
            lis[it - lis.begin()] = a[i];
        }

        pr.push_back({(int)lis.size(), prmx});
    }

    int result = 0;

    lis.clear();
    for (int i = N - 1; ~i; i--) {
        auto it = upper_bound(lis.begin(), lis.end(), -a[i]);
        if (it == lis.end()) {
            lis.push_back(-a[i]);
        } else {
            lis[it - lis.begin()] = -a[i];
        }

        if (i > 0 && pr[i - 1][1] > -lis.back()) {
            result = max(result, pr[i - 1][0] + (int)lis.size());
        }
    }

    cout << result << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
