#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0), ios::sync_with_stdio(0);
    
    int N;
    cin >> N;

    int result = 0, a_before_g = 0, a_after_g = 0;

    while (N--) {
        char C;
        cin >> C;

        if (C == 'C') continue;
        if (C == 'A') a_before_g++;
        else if (C == 'G') {
            a_after_g += a_before_g;
            a_before_g = 0;
        }
        else {
            result += a_after_g;
        }
    }

    cout << result;
}
