#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N), pmx(N);
    for (int& x : a) cin >> x;

    pmx[0] = a[0];
    bool mon = 1;
    for (int i = 1; i < N; i++) {
        if (a[i - 1] > a[i]) mon = 0;
        pmx[i] = max(pmx[i - 1], a[i]);
    }

    if (mon) {
        cout << "-1";
        exit(0);
    }

    int mx = 0, resl = -1, resr = -1;
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
        if (i - r > mx) {
            mx = i - r;
            resl = r;
            resr = i;
        }
    }

    cout << resl + 1 << " " << resr + 1 << "\n";
}
