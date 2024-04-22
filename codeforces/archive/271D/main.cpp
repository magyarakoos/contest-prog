#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MAXN = 2e6;

bool bad[26];
int trie[MAXN][26];
int main() {
	cin.tie(0), ios::sync_with_stdio(0);

    string s;
    cin >> s;

    for (int i = 0; i < 26; i++) {
        char c;
        cin >> c;
        bad[i] = c == '0';
    }

    int K;
    cin >> K;

    vector<int> prefix_sum(s.size() + 1);
    for (int i = 1; i <= s.size(); i++) {
        prefix_sum[i] = prefix_sum[i - 1] + bad[s[i - 1] - 'a'];
    }

    int node_count = 1;
    for (int i = 0; i < s.size(); i++) {
        int node = 1;
        for (int j = i; j < s.size(); j++) {
            int range_sum = prefix_sum[j + 1] - prefix_sum[i];
            if (range_sum > K) {
                break;
            }

            char c = s[j] - 'a';
            if (trie[node][c] == 0) {
                trie[node][c] = ++node_count;
            }

            node = trie[node][c];
        }
    }

    cout << node_count - 1;
}
