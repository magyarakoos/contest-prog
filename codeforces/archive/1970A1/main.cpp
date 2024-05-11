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
    vector<int> bal(N);
    for (int i = 1; i < N; i++) {
        bal[i] = bal[i - 1] + (s[i - 1] == '(' ? 1 : -1);
    }
    vector<Item> v(N);
    for (int i = 0; i < N; i++) {
        v[i] = {i, bal[i], s[i]};
    }
    sort(all(v), [](Item a, Item b) {
        if (a.balance < b.balance) return true;
        if (a.balance > b.balance) return false;
        return a.index > b.index;
    });
    for (Item x : v) cout << x.c;
    cout << "\n";
}