#include <array>
#include <iostream>

using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    array<bool, 3> a;
    for (int i = 0; i < 3; i++) {
        int x;
        cin >> x;
        a[x - 1] = 1;
    }
    for (int i = 0; i < 3; i++) { if (!a[i]) }
}
