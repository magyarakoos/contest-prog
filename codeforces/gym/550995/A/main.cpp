#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int& x : a) cin >> x;

    for (int i = 1; i < N; i++) {
        if (a[i - 1] != a[i]) {
            cout << "1\n";
            return;
        }
    }

    cout << N << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
