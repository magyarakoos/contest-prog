#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s >> s;
	string t = s;
	sort(t.begin(), t.end());
	cout << (s == t ? "YES\n" : "NO\n");
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) solve();
}

