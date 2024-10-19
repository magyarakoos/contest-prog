#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    array<int, 26> h = {0};
    for (char c : s) h[c - 'a']++;

    string result;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < 26; j++) {
            if (result.empty() || result.back() != j + 'a') {
                result += j + 'a';
                h[j]--;
                break;
            }
        }
    }
}
