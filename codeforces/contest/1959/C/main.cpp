#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> lC(26), uC(26);
        while (N--) {
            char c;
            cin >> c;
            if (islower(c)) {
                lC[c - 'a']++;
            } else {
                uC[c - 'A']++;
            }
        }
        int res = 0, diff_sum = 0;
        for (int i = 0; i < 26; i++) {
            res += min(lC[i], uC[i]);
            diff_sum += abs(lC[i] - uC[i]) / 2;
        }
        cout << res + min(diff_sum, K) * 2 << "\n";
    }
}