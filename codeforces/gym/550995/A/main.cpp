#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int& x : a) cin >> x;

    for (int x : a) {
        if (prv && x != prv) {
            cout << "1\n";
            return;
        }
        prv = x;
    }

    cout << N << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
