// thanks to the creative genius of TomaSajt
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

    int best_l = -1, best_r = -1, best_save = 0, 
        l = 0, r = 0, save = 0;

    for (; r < N; r++) {
        if (save + S[r] <= 0) {
            save = 0;
            l = r + 1;
        } else {
            save += S[r];
            if (best_save < save) {
                best_save = save;
                best_l = l;
                best_r = r;
            }
        }
    } 

    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (i < best_l || i > best_r) {
            
        }
    }
}
