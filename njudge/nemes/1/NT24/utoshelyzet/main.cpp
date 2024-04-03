#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v(8, vector<int>(8));

void setvals(int X, int Y, int type, bool diag) {
    for (int i = Y + 1; i < 8; i++) {
        v[i][X] = type;
    }
    for (int i = Y - 1; i >= 0; i--) {
        v[i][X] = type;
    }
    for (int j = X + 1; j < 8; j++) {
        v[Y][j] = type;
    }
    for (int j = X - 1; j >= 0; j--) {
        v[Y][j] = type;
    }

    if (diag) {
        for (int i = Y + 1, j = X + 1; i < 8 && j < 8; i++, j++) {
            v[i][j] = type;
        }
        for (int i = Y - 1, j = X - 1; i >= 0 && j >= 0; i--, j--) {
            v[i][j] = type;
        }
        for (int i = Y - 1, j = X + 1; i >= 0 && j < 8; i--, j++) {
            v[i][j] = type;
        }
        for (int i = Y + 1, j = X - 1; i < 8 && j >= 0; i++, j--) {
            v[i][j] = type;
        }
    }

    v[Y][X] = type;
}

bool valid(int X, int Y, int T) {
    if (T == 1) return 1;
    for (int i = Y + 1, j = X + 1; i < 8 && j < 8; i++, j++) {
        if (v[i][j] > 1) return 0;
    }
    for (int i = Y - 1, j = X - 1; i >= 0 && j >= 0; i--, j--) {
        if (v[i][j] > 1) return 0;
    }
    for (int i = Y - 1, j = X + 1; i >= 0 && j < 8; i--, j++) {
        if (v[i][j] > 1) return 0;
    }
    for (int i = Y + 1, j = X - 1; i < 8 && j >= 0; i++, j--) {
        if (v[i][j] == 2) return 0;
    }
    return 1;
}

ofstream fout("out.2");
#define cout fout

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    while (N--) {
        int T, X, Y;
        cin >> T >> Y >> X;
        X--; Y--;

        for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << v[i][j];
        }cout<<"\n";}
        
        if (T == 3) {
            setvals(X, Y, 0, v[Y][X] == 2);
            cout << "-\n";
            continue;
        }

        if (v[Y][X] || !valid(X, Y, T)) {
            cout << "NEM\n";
            continue;
        }

        setvals(X, Y, T, T == 2);
        cout << "IGEN\n";
    }

    for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
        cout << v[i][j];
    }cout<<"\n";}
}