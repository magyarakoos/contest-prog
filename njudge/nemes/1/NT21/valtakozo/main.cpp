#include <bits/stdc++.h>
using namespace std;

bool can_finish(const array<int, 26>& h, int j) {
    int sum = 0;
    for (int i = 0; i < 26; i++) { sum += h[i]; }
}

int main() {
    string s;
    cin >> s;

    array<int, 26> h = {0};
    for (char c : s) h[c - 'a']++;

    string result;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < 26; j++) {
            if (h[j] > 0 && can_finish(h, j) &&
                (result.empty() || result.back() != j + 'a')) {
                result += j + 'a';
                h[j]--;
                break;
            }
        }
    }

    cout << result;
}
