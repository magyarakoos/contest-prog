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
        int mn = i + 1;
        for (int j = 0; j < 52; j++) {
            if (last[j] == -1) {
                mn = i + 1;
                break;
            }
            mn = min(mn, last[j]);
        }
        result = min(result, i - mn + 1);
    }

    cout << result << "\n";
}
