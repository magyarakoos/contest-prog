#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<bool> a(M);
    while (N--) {
        int K;
        cin >> K;
        while (K--) {
            int P;
            cin >> P;
            a[P - 1] = 1;
        }
    }
    for (int i = 0; i < M; i++) {
        if (!a[i]) {
            cout << "NEM\n";
            exit(0);
        }
    }
    cout << "IGEN\n";
}
