#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

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
            for (int i = Y; i < 8; i++) {
                v[i][X] = 0;
            }
            cout << "-\n";
            continue;
        }

        if (v[Y][X]) {
            cout << "NEM\n";
            continue;
        }

        if (T == 1) {
            
        }
        if (T == 2) {

        }
    }
}