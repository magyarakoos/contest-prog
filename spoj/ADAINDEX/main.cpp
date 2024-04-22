// Megoldva, submission id: 32927455
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MAXN = 1e6;

int trie[MAXN][26];
int cnt[MAXN];
int node_count = 1;
int main() {
	cin.tie(0), ios::sync_with_stdio(0);
	int N, Q;
	cin >> N >> Q;
	while (N--) {
		string s;
		cin >> s;
		int node = 1;
		for (char c : s) {
			c -= 'a';
			if (trie[node][c] == 0) {
				node_count++;
				trie[node][c] = node_count;
			}
			node = trie[node][c];
			cnt[node]++;
		}
	}
	while (Q--) {
		string s;
		cin >> s;
		int node = 1, res = 0;
		for (char c : s) {
			c -= 'a';
			if (trie[node][c] == 0) {
				cout << "0\n";
				goto next;
			}
			node = trie[node][c];
			res = cnt[node];
		}
		cout << res << "\n";
		next:continue;
	}
}
