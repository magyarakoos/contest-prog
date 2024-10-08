#include <iostream>
#include <map>
using namespace std;

int main() {
    int N;
    string s;
    cin >> N >> s;

    map<char, int> last;
    for (char c : s) last[c] = -1;
    int result = N;

    for (int i = 0; i < N; i++) {
        last[s[i]] = i;
        int mn = -N;
        for (auto [_, j] : last) {
            if (j == -1) {
                mn = -N;
                break;
            }
            mn = min(mn, j);
        }
        cout << mn << " " << i << "  ";
        result = min(result, i - mn + 1);
    }

    cout << result << "\n";
}
