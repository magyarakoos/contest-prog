#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<bool> alpha(26);
    while (N--) {
        char c;
        cin >> c;
        alpha[tolower(c) - 'a'] = 1;
    }
    cout << (all_of(alpha.begin(), alpha.end(), [](bool b){ return b; }) ? "YES" : "NO");
}
