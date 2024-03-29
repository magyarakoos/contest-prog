#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;
using point = array<int, 2>;

int main() {
    speed;

    int N;
    cin >> N;
    unordered_map<string, int> teamS;
    while (N--) {
        string s;
        cin >> s;
        sort(all(s));
        teamS[s]++;
    }
    
    for (auto [id, db] : teamS) {
        if (db & 1) {
            cout << id;
            exit(0);
        }
    }
}
