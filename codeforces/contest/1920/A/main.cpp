#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> no;
        int bottom = -1, top = INT_MAX;
        for (int i = 0; i < N; i++) {
            int a, x;
            cin >> a >> x;
            if (a == 1) {
                bottom = max(bottom, x);
            }
            else if (a == 2) {
                top = min(top, x);
            }
            else {
                no.push_back(x);
            }
        }
        int k = top - bottom + 1;
        for (int x : no) {
            if (bottom <= x && x <= top) {
                k--;
            }
        }
        cout << max(k, 0) << '\n';
    }
}