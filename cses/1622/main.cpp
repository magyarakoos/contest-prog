#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    string s;
    cin >> s;

    sort(s.begin(), s.end());

    vector<string> result;

    do {
        result.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << result.size() << "\n";
    for (const string& t : result) {
        cout << t << "\n";
    }
}
