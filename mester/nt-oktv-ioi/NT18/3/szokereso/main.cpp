#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int N;
string s;
vector<string> m;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    cin >> N;
    
    m.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> m[i];
    }

    cin >> s;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (m[i][j] == s[s]) {
                
            }
        }
    }
}