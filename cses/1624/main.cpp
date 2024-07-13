#include <iostream>

using namespace std;

bool board[8][8], colS[8], diagA[15], diagB[15];
int result;

void backtrack(int i) {
    if (i == 8) {
        result++;
        return;
    }
    for (int j = 0; j < 8; j++) {
        if (board[i][j] && !colS[j] && !diagA[j - i + 7] && !diagB[i + j]) {
            colS[j] = diagA[j - i + 7] = diagB[i + j] = 1;
            backtrack(i + 1);
            colS[j] = diagA[j - i + 7] = diagB[i + j] = 0;
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char c;
            cin >> c;
            board[i][j] = c == '.';
        }
    }

    backtrack(0);

    cout << result << "\n";
}
