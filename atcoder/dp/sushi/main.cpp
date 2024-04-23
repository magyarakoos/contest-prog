#include <bits/stdc++.h>
using namespace std;
using u8 = int;
#define sum(v) accumulate(v.begin(), v.end(), 0)
#define size(v) (int)v.size()

map<vector<u8>, double> m;

double solve(vector<u8> v) {
    if (!sum(v)) {
        return 0;
    }

    sort(v.begin(), v.end());
    if (m.count(v)) {
        return m[v];
    }

    double a = 0;
    for (int i = 0; i < size(v); i++) {
        if (!v[i]) continue;
        v[i]--;
        a += solve(v) + 1;
        v[i]++;
    }
    cerr << a << " | ";
    for (u8 x : v) cout << x << " ";
    cout << endl;
    sleep(1);
    m[v] = a;
    return a;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<u8> v(N);
    for (u8& x : v) cin >> x;
    cout << fixed << setprecision(20) << solve(v);
}
