#include <bits/stdc++.h>
using namespace std;

string recur(int n) {
    return (n ? recur(n / 2) + (char)((n % 2) + '0') : "");
}

string binary(int n) {
    return n ? recur(n) : "0";
}

int main() {
    int n;
    // null terminatorral (\0) lehet megszakítani
    while (cin >> n) {
        cout << binary(n) << '\n';
    }
}