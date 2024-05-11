#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()

using namespace std;
using ll = long long;

struct Item {
    int index;
    int balance;
    char c;
};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    string s;
    cin >> s;
    int N = sz(s);
    vector<int> bal(N + 1);
    for (int i = 1; i <= N; i++) {
        bal[i] = bal[i - 1] + (s[i - 1] == '(' ? 1 : -1);
    }
}