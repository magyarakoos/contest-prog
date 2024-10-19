#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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
    partial_sum(na.rbegin(), na.rend(), sz.begin());
}
