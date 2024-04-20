#include <bits/stdc++.h>
using namespace std;

bool issubseq(const string& s, const string& t) {
    int i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) {
            j++;
        }
        i++;
    }
    return j >= t.size();
}

int main() {
    string s, t;
    cin >> s >> t;
    for (char& c : t) c = tolower(c);
    if (t[2] == 'x') {
        cout << (issubseq(s, t.substr(0, 2)) ? "Yes" : "No");
    } else {
        cout << (issubseq(s, t) ? "Yes" : "No");
    }
}
