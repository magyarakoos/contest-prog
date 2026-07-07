#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, d, v;
    cin >> n >> d >> v;
    int result = 0;
    while (n--) {
        int s;
        cin >> s;
        result += s > v;
    }
    cout << result << "\n";
}
