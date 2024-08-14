#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    string a, b;
    cin >> a >> b;

    reverse(all(a));
    reverse(all(b));

    for (int i = 0; i < min(size(a), size(b)); i++) {
        if (a[i] + b[i] >= 106) {
            cout << "Hard";
            exit(0);
        }
    }

    cout << "Easy";
}
