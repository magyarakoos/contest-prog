#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;
using point = array<int, 2>;

string base3(int n) {
    string s;
    while (n > 0) {
        int mod = n % 3;
        s = to_string(mod) + s;
        n /= 3;
    }
    return s;
}

int main() {
    speed;

    ll K, row = 0, col = 0;
    cin >> K;
    while (K--) {
        char m;
        cin >> m;

        if (m == '0') { cout << "DL | ";
            row++;
            col *= 3;
        }
        else if (m == '1') { cout << "DM | ";
            row++;
            col *= 3;
            col++;
        }
        else if (m == '2') { cout << "DR | ";
            row++;
            col *= 3;
            col += 2;
        }
        else if (m == '3') { cout << "UP | ";
            row--;
            col /= 3;
        }
        else if (m == '4') { cout << "L  | ";
            col--;
        }
        else { cout << "R  | ";
            col++;
        }
    }
    cout << row << '\n' << base3(col);
}
