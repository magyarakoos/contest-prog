#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int N;
    cin >> N;
    map<string, int> scoreS;
    map<int, string> firstS;
    cout << "\n";
    while (N--) {
        string name;
        int score;
        cin >> name >> score;
        scoreS[name] += score;
        cout << name << " " << scoreS[name] << "\n";
        if (!firstS.count(scoreS[name])) {
            firstS[scoreS[name]] = name;
        }
    }
    int mx = INT_MIN;
    for (const auto& [k, v] : scoreS) {
        mx = max(mx, v);
    }
    cout << firstS[mx];
}
