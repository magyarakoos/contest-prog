#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0), ios::sync_with_stdio(0);

    ll N, X;
    cin >> N >> X;

    string s = bitset<64>(X).to_string();

    while (N--) {
        char c;
        cin >> c;
        if (c == 'U') {
            s.pop_back();
        }
        if (c == 'L') {
            s += '0';
        }
        if (c == 'R') {
            s += '1';
        }
    }

    cout << stoll(s, nullptr, 2);
}
