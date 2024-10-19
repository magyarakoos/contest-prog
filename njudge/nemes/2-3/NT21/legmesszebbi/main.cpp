#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N), pmx(N);
    for (int& x : a) cin >> x;

    pmx[0] = a[0];
    for (int i = 1; i < N; i++) {
        pmx[i] = max(pmx[i - 1], a[i]);
    }

    for (int i = 1; i < N; i++) {
        int l = -1, r = i - 1;
        while (r - l > 1) {
            int m = (r + l) / 2;
            if (pmx[m] > a[i]) {
                r = m;
            } else {
                l = m;
            }
        }
        cout << r << "\n";
    }
}
