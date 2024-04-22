#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e6;

int trie[MAXN][26];
void solve() {
	memset(trie, 0, sizeof(trie));
	int node_count = 1;
	
	string s;
	cin >> s;
	
	for (int i = 0; i < s.size(); i++) {
		int node = 1;
		for (int j = i; j < s.size(); j++) {
			int c = s[j] - 'A';
			if (trie[node][c] == 0) {
				trie[node][c] = ++node_count;
			}
			node = trie[node][c];
		}
	}
	
	cout << node_count - 1 << "\n";
}

int main() {
	cin.tie(0), ios::sync_with_stdio(0);
    int T;
	cin >> T;
	while (T--) solve();
}

