#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> a(N), ps(N);
    for (int& x : a) cin >> x;
    partial_sum(a.begin(), a.end(), ps.begin());
    ll result = 0;
    for (int i = 0; i < N; i++) {
        if (!a[i]) result += ps[i];
    }
}
