#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int N = s.size();

    array<int, 26> h = {0};
    for (char c : s) h[c - 'a']++;
}
