#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> last(52, -1);
    int N;
    string s;
    cin >> N >> s;

    int result = N;

    for (int i = 0; i < N; i++) {
        last[s[i] - (s[i] < 'a' ? 'A' : 'a')] = i;
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
}
