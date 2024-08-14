#include <bits/stdc++.h>
using namespace std;

int sc, tc;

int main() {
    string X;
    cin >> X;

    for (char c : X) {
        if (c == 'S') {
            sc++;
        }
        else if (sc) {
            sc--;
        }
        else {
            tc++;
        }
    }

    cout << sc + tc;
}
