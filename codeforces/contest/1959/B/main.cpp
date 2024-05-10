#include <bits/stdc++.h>
using namespace std;

// a < b ->  1
// a = b ->  0
// a > b -> -1
int cmp(string a, string b) {
    if (a == b) return 0;

    int cntA = count(a.begin(), a.end(), 'X'),
        cntB = count(b.begin(), b.end(), 'X');
    
    char lA = a.back(),
         lB = b.back();
    
    if (lA == 'M') {
        return lB == 'S' ? -1 : 1;
    }
    if (lB == 'M') {
        return lA == 'S' ? 1 : -1;
    }

    if (lA == 'S' && lB == 'L') {
        return 1;
    }
    if (lA == 'L' && lB == 'S') {
        return -1;
    }

    if (lA == 'S' && lB == 'S') {
        return
            cntA > cntB ? 1 : -1;
    }

    return cntA < cntB ? 1 : -1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string a, b;
        cin >> a >> b;
        if (a == b) {
            cout << "=\n";
            continue;
        }

    }
}