#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    map<string, vector<string>> g; 

    while (N--) {
        string U, V;
        cin >> U >> V;
        g[U].push_back(V);
    }

    vector<string> result;

    for (const auto& [key, values] : g) {
        for (const string& v : values) {
            if (!g[v].empty()) {
                result.push_back(key);
                break;
            }
        }
    }
    
    if (result.empty()) {
        cout << 0;
        exit(0);
    }

    cout << size(result) << '\n';
    for (const string& v : result) cout << v << '\n';
}