#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int N;
    cin >> N;
    map<string, int> scoreS;
    while (N--) {
        string name;
        int score;
        cin >> name >> score;
        scoreS[name] += score;
    }
    int mx = INT_MIN;
    for (const auto& [k, v] : scoreS) {
        mx = max(mx, v);
    }
}
