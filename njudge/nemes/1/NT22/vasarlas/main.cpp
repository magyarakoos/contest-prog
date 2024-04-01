#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()

int main() {
	cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> A(N), B(N), psA(N + 1), psB(N + 1);

    for (int& x : A) cin >> x;
    for (int& x : B) cin >> x;

    partial_sum(all(A), psA.begin() + 1);
    partial_sum(all(B), psB.begin() + 1);

    int best_i = 0, best_j = 0, best_save = INT_MIN;

    for (int i = 0; i < N; i++) {
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
    }

    cout << min(
        psB.back(), 
        psB[best_i] + (psA[best_j + 1] - psA[best_i]) + (psB.back())
    );
}
