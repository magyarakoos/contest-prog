#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()

int main() {
	cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> A(N), B(N), S(N);

    for (int& x : A) cin >> x;
    for (int& x : B) cin >> x;
    for (int i = 0; i < N; i++) S[i] = B[i] - A[i];

    /*for (int i = 0; i < N; i++) {
    int best_i = 0, best_j = 0, best_save = INT_MIN;
        for (int j = i; j < N; j++) {
            int costA = psA[j + 1] - psA[i];
            int costB = psB[j + 1] - psB[i];

            int save = costB - costA;

            if (best_save < save) {
                best_save = save;
                best_i = i;
                best_j = j;
            }
        }
    cout << min(
        psB.back(), 
        psB[best_i] + (psA[best_j + 1] - psA[best_i]) + (psB.back() - psB[best_j + 1])
    );
    }*/

    int best_l = -1, best_r = -1, best_save = 0, 
        l = 0, r = 0, save = 0;

    for (; r < N; r++) {
        if (save + S[r] <= 0) {
            save = 0;
            l = r + 1;
        }
    } 
}
