#include <iostream>

using namespace std;

int board[3][3];
int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;
        board[X - 1][Y - 1] = i % 2 + 1;
    }
}
