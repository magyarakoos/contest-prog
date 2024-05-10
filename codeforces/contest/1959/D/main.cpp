#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        char c;
        cin >> N >> c;
        string s;
        cin >> s;
        s += s;

        int M = s.size();

        vector<int> fc(M);

        int i = N;
        while (i < M && s[i] != 'g') i++;
        
        for (; i >= 0; i--) {
            if (s[i] == 'g') {
                fc[i] = i;
            } else {
                fc[i] = fc[i + 1];
            }
        }

        int res = 0;
        for (int i = 0; i < N; i++) {
            if (s[i] == c) {
                res = max(res, fc[i] - i);
            }
        }

        cout << res << "\n";
    }
}