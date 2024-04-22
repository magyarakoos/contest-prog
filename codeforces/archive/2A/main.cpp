#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int mx = INT_MIN;
    map<string, int> scoreS;
    map<int, string> firstS;
    while (N--) {
        string name;
        int score;
        cin >> name >> score;
        scoreS[name] += score;
        if (!firstS.count(scoreS[name])) {
            firstS[scoreS[name]] = name;
        }
    }
    
    for (const auto& [k, v] : scoreS) {

    }
}
