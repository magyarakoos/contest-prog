#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> a(N), ps(N + 1);
    for (int& x : a) cin >> x;

    for (int i = 1; i <= N; i++) {
        ps[i] = ps[i - 1] ^ a[i - 1];
    }

    while (Q--) {
        int L, R;
        cin >> L >> R;
        cout << (ps[R] ^ ps[L - 1]) << "\n";
    }
}
