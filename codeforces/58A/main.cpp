#include <bits/stdc++.h>
using namespace std;

int p;
int main() {
    string s;
    cin >> s;
    for (char c : s) {
        p += "hello"[p] == c;
        if (p == 5) goto end;
    }
    end: cout << (p == 5 ? "YES" : "NO");
}
