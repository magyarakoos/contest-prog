#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    int N;
    cin >> N;
    if (N == 4) {
        cout << "2 4 1 3\n";
        exit(0);
    }
    vector<int> a(N);
    for (int i = 0; i < N; i += 2) {
        a[i / 2] = i;
    }
    for (int i = 1; i < N; i += 2) {
        a[(N - 1) / 2 + (i + 1) / 2] = i;
    }
    for (int i = 1; i < N; i++) {
        if (abs(a[i - 1] - a[i]) == 1) {
            cout << "NO SOLUTION\n";
            exit(0);
        }
    }
    for (int x : a) cout << x + 1 << " ";
    cout << "\n";
}
