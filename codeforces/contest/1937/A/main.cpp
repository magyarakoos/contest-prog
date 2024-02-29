#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    const vector<int> v = {

    };
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << upper_bound(all(v), N) << '\n';
    }
}