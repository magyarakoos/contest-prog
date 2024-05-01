#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

vector<bool> s;

int l(int i) {
    if (i == 0) return sz(s) - 1;
    return i - 1;
}

int r(int i) {
    if (i == sz(s) - 1) return 0;
    return i + 1;
}

int val(int i) {
    return s[l(i)] + s[i] + s[r(i)];
}

#define cases 1
void solve() {
    int N;
    cin >> N;
    s.assign(N, 0);
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        s[i] = c == 'U';
    }
    int turn = 0;
    while (N > 0) {
        //for (bool b : s) {cerr << b;} cerr << "\n";
        int bst_i = -1;
        for (int i = 0; i < N; i++) {
            if ((bst_i == -1 && s[i]) || (val(bst_i) < val(i) && s[i])) {
                bst_i = i;
            }
        }
        if (bst_i == -1) {
            break;
        }
        turn++;
        s[l(bst_i)] = !s[l(bst_i)];
        s[r(bst_i)] = !s[r(bst_i)];
        s.erase(s.begin() + bst_i);
        N--;
    }
    //cerr << turn << "\n";
    cout << (turn & 1 ? "YES" : "NO") << "\n";
}   

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
