#include <iostream>
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    long long N;
    cin >> N;
    cout << (N % 31 ? "NEM\n" : "IGEN\n");
    while (N > 0) {
        N = N / 10 - (N % 10) * 3;
        if (N >= 0) {
            cout << N << ' ';
        }
    }
    cout << '\n';
}
