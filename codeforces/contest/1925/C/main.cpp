#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K, M;
    cin >> N >> K >> M;

    vector<bool> alpha(K);
    vector<int> countS(K);
    
    int count = 0;

    string s;
    cin >> s;

    for (int i = 0; i < M; i++) {
        char c = s[i];
        int ind = c - 'a';
        if (ind >= K) continue;

        countS[ind]++;
        alpha[ind] = 1;

        if (all_of(alpha.begin(), alpha.end(), [](bool b){ return b; })) {
            fill(alpha.begin(), alpha.end(), 0);
            count++;
        }
    }

    if (count >= N) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";

    vector<int> latf(K, M * 2);
    int p = 0;

    for (int i = 0; i < N; i++) {

        fill(latf.begin(), latf.end(), M * 2);

        for (int j = p + 1; j < M; j++) {
            int ind = s[j] - 'a';
            latf[ind] = min(latf[ind], j);
        }

        p = *max_element(latf.begin(), latf.end());
        
        cout << (char)(max_element(latf.begin(), latf.end()) - latf.begin() + 'a');
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
