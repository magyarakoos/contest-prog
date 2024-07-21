#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    ll N;
    cin >> N;

    if (N * (N + 1) / 2 & 1) {
        cout << "NO\n";
        exit(0);
    }

    ll x = N * (N + 1) / 4;

    vector<int> a, b;

    while (N--) {
        if (x >= N + 1) {
            x -= N + 1;
            a.push_back(N + 1);
        } else {
            b.push_back(N + 1);
        }
    }

    cout << "YES\n" << a.size() << "\n";
    for (int x : a) cout << x << " ";
    cout << "\n" << b.size() << "\n";
    for (int x : b) cout << x << " ";
    cout << "\n";
}
