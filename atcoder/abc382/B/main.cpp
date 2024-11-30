#include <iostream>
using namespace std;
int main() {
    int N, D;
    string S;
    cin >> N >> D >> S;
    for (int i = N - 1; ~i; i--) {
        if (D && S[i] == '@') {
            S[i] = '.';
            D--;
        }
    }
    cout << S << "\n";
}
