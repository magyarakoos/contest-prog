#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int A, B;
        cin >> A >> B;
        cout << (abs(A - B) % 2 ? "Alice" : "Bob") << '\n';
    }
}