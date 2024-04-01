#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0), ios::sync_with_stdio(0);
    
    string s;
    cin >> s >> s;

    int result = 0, before_g = 0, after_g = 0;

    while (N--) {
        char C;
        cin >> C;
        if (C == 'A') after_g++;
        if (C == 'G') {
            before_g += after_g;
            after_g = 0;
        }
        if (C == 'T') {
            result += before_g;
        }
    }

    cout << result;
}
