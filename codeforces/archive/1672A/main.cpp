#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int cuts = 0;
        while (N--) {
            int x;
            cin >> x;
            cuts += x - 1;
        }
        cout << (cuts & 1 ? "errorgorn" : "maomao90") << '\n';
    }
}