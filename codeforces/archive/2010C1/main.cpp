#include <iostream>

using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    string t;
    cin >> t;
    int N = t.size();

    for (int m = N - 1; m >= 0; m--) {
        if (t.substr(0, m) == t.substr(N - m)) {
            cout << "Yes\n" << t.substr(0, m);
            exit(0);
        } else {
            cout << t.substr(0, m) << " " << t.substr(N - m) << "\n";
        }
    }
    cout << "NO\n";
}
