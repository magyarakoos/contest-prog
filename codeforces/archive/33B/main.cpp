// O(N + |s|)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define smin(x, y) x = min(x, y)

const int INF = 1e9;

int main() {
	cin.tie(0), ios::sync_with_stdio(0);

    string s, t;
    int N;
    cin >> s >> t >> N;

    if (sz(s) != sz(t)) {
        cout << "-1\n";
        exit(0);
    }

    vector FW(26, vector<int>(26, INF));

    for (int i = 0; i < 26; i++) FW[i][i] = 0;

    while (N--) {
        char U, V;
        int W;
        cin >> U >> V >> W;
        smin(FW[U - 'a'][V - 'a'], W);
    }

    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                smin(FW[i][j], FW[i][k] + FW[k][j]);
            }
        }
    }

    int cost = 0;
    string result;
    for (int i = 0; i < sz(s); i++) {
        int mn = INF;
        char mn_c = '$';
        for (int j = 0; j < 26; j++) {
            if (FW[s[i] - 'a'][j] + FW[t[i] - 'a'][j] < mn) {
                mn = FW[s[i] - 'a'][j] + FW[t[i] - 'a'][j];
                mn_c = j + 'a';
            }
        }
        if (mn == INF) {
            cout << "-1\n";
            exit(0);
        }
        cost += mn;
        result += mn_c;
    }

    cout << cost << "\n" << result << "\n";;
}
