#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)

using namespace std;

int main() {
    speed;

    map<string, int> m = {
        {"-----", 0},
        {".----", 1},
        {"..---", 2},
        {"...--", 3},
        {"....-", 4},
        {".....", 5},
        {"-....", 6},
        {"--...", 7},
        {"---..", 8},
        {"----.", 9},
    };
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i += 5) {
        cout << m[s.substr(i, 5)];
    }
}
