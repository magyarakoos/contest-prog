#include <bits/stdc++.h>
using namespace std;
#define int int64_t

bool bad[26];
int trie[(int)2e6][26];

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);

    string s;
    cin >> s;

    for (int i = 0; i < 26; i++) {
        char c;
        cin >> c;
        bad[i] = c == '0';
    }

    int k;
    cin >> k;

    vector<int> ps(s.size() + 1);
    for (int i = 1; i < ps.size(); i++) {
        ps[i] = ps[i - 1] + bad[s[i - 1] - 'a'];
    }

    int cnt = 1;
    for (int i = 0; i < s.size(); i++) {
        int node = 1;
        for (int j = i; j < s.size(); j++) {
            int range_sum = ps[j + 1] - ps[i];
            if (range_sum > k) { break; }

            int c = s[j] - 'a';
            if (trie[node][c] == 0) {
                trie[node][c] = ++cnt;
            }

            node = trie[node][c];
        }
    }

    cout << cnt - 1;
}
