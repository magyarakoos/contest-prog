#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N), na(N), po(N), sz(N);
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        na[i] = !(a[i] = c == '1');
    }

    partial_sum(a.begin(), a.end(), po.begin());
    partial_sum(na.rbegin(), na.rend(), sz.rbegin());

    int result = min(po.back(), sz.front());
    for (int i = 1; i < N - 1; i++) {
        result = min(result, po[i - 1] + sz[i]);
    }

    cout << result;
}
