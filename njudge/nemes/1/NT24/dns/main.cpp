#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0), ios::sync_with_stdio(0);
    
    int N;
    cin >> N;

    int result = 0, before_g = 0, after_g = 0;

    while (N--) {
        char C;
        cin >> C;

        if (C == 'C') continue;
        if (C == 'A') before_g++;
        else if (C == 'G') {
            after_g += before_g;
            before_g = 0;
        }
        else {
            result += after_g;
        }
    }

    cout << result;
}
