#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t, u = "AOYEUI";
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (u.find(toupper(s[i])) == u.npos) {
            t += '.';
            t += tolower(s[i]);
        }
    }
    cout << t;
}
