#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;

int main() {
    speed;

    ll K, row = 0;
    cin >> K;

    Integer col;

    while (K--) {
        char m;
        cin >> m;

        if (m == '0') {
            row++;
            col.mul3();
        }
        else if (m == '1') {
            row++;
            col.mul3();
            col.add();
        }
        else if (m == '2') {
            row++;
            col.mul3();
            col.add();
            col.add();
        }
        else if (m == '3') {
            row--;
            col.div3();
        }
        else if (m == '4') {
            col.sub();
        }
        else {
            col.add();
        }
    }

    cout << row << '\n';
    col.print();
}
