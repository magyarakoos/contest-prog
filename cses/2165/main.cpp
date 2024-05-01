#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()

using namespace std;
using ll = long long;

vector<int> a, b;



int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    cout << sz(a) << "\n";
    for (int i = 0; i < sz(a); i++) {
        cout << a[i] << " " << b[i] << "\n";
    }
}