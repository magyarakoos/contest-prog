#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<array<int, 2>> kidS(N);
    vector<int> capS(M + 1);
    for (auto& [a, b] : kidS) cin >> a >> b;
    for (int i = 1; i <= M; i++) cin >> capS[i];
    
    for (int mask = 0; mask < (1 << N); mask++) {
        cout << bitset<9>(mask) << "\n";
        bool valid = 1;
        vector<int> countS(M + 1), placeS(N + 1);
        for (int i = 0; i < N; i++) {
            bool bit = (mask << i) & 1;

            placeS[i] = kidS[i][bit];
            countS[placeS[i]]++;

            if (countS[placeS[i]] > capS[placeS[i]]) {
                valid = 0;
            }
        }
        
        if (!valid) {
            for (int p : countS) cout << p << " ";
            cout << "\n";
        }
    }

    assert(0);
}