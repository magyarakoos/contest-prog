#include <iostream>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    ll A, B, result = 0;
    cin >> A >> B;

    while (A && B) {
        if (A > B) swap(A, B);
        result += B / A;
        B -= B / A * A;
    }

    cout << result << "\n";
}
