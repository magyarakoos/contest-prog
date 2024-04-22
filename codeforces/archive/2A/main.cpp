#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int N;
    cin >> N;
    map<string, int> scoreS;
    vector<pair<string, int>> stateS;
    while (N--) {
        string name;
        int score;
        cin >> name >> score;
        scoreS[name] += score;
        stateS.push_back({name, scoreS[name]});
    }
    
    int mx = INT_MIN;
    vector<string> mxS;
    for (const auto& [k, v] : scoreS) {
        if (mx < v) {
            mx = v;
            mxS.clear();
            mxS.push_back(k);
        }
        else if (mx == v) {
            mxS.push_back(k);
        }
    }

}
