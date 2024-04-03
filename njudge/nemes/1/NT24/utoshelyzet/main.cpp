#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    vector<vector<int>> v(8, vector<int>(8));
    int N;
    cin >> N;
    while (N--) {
        int T, X, Y;
        cin >> T >> Y >> X;
        X--; Y--;
        
        if (T == 3) {
            for (int i = Y; i < 8; i++) {
                v[i][X] = 0;
            }
            for (int i = Y - 1; i >= 0; i--) {
                v[i][X] = 0;
            }
            for (int j = X; j < 8; j++) {
                v[Y][j] = 0;
            }
            for (int j = X - 1; j >= 0; j--) {
                v[Y][j] = 0;
            }



            cout << "-\n";
            continue;
        }

        if (v[Y][X]) {
            cout << "NEM\n";
            continue;
        }

        if (T == 1) {
            
        } else {

        }
    }
}