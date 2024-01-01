#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)

using namespace std;

/*const int N_lengthS[13] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

const int S_lengthS[13] = {
    0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};*/

const int W_lengthS[13] = {
    0, 31, 30, 30, 31, 30, 30, 31, 30, 30, 31, 30, 30
};

int main() {
    speed;

    int Y, M, D;
    cin >> Y >> M >> D;
    cout << Y;
    if (Y % 4) {
        if (M == 12 && D == 31) {
            cout << " 12 VN";
        } else {
            cout << ' ' << M << ' ' << D;
        }
    } else {
        if (M == 7 && D == 1) {
            cout << " 6 SZN";
            exit(0);
        } else if (M >= 7) {
            if (D == 1) {
                M--;
                D = W_lengthS[M];
            } else {
                D--;
            }
        }
        cout << ' ' << M << ' ' << D;
    }
}
