#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<array<int, 2>> kidS(N);
    vector<int> capS(M);
    for (auto& [a, b] : kidS) cin >> a >> b;
    for (int& x : capS) cin >> x;
    
    for (int mask = 0; mask < (1 << N); mask++) {
        cout << bitset<9>(mask) << "\n";
        bool valid = 1;
        vector<int> countS(M), placeS(N);
        for (int i = 0; i < N; i++) {
            bool bit = (mask << i) & 1;

            if (!kidS[i][bit]) {
                valid = 0;
                break;
            }

            placeS[i] = kidS[i][bit];
            countS[placeS[i] - 1]++;

            if (countS[placeS[i] - 1] > capS[placeS[i] - 1]) {
                valid = 0;
                for (int p : countS) cout << p << " ";
                cout << "\n";
                break;
            }
        }
        
        if (valid) {
            for (int p : placeS) cout << p << " ";
            exit(0);
        }
    }

    assert(0);
}