#include <iostream>
#include <map>

using namespace std;

int main() {
    int N;
    cin >> N;
    map<int, int> m;
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        cout << (m.count(A) ? m[A] : -1) << "\n";
        m[A] = i + 1;
    }
}
