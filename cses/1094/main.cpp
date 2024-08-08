#include <iostream>
using namespace std;
using ll = long long;

int main() {
    int N, h = 0;
    ll result = 0;
    cin >> N;
    while (N--) {
        int x;
        cin >> x;
        result += max(0, h - x);
        h = max(h, x);
    }
    cout << result << "\n";
}
