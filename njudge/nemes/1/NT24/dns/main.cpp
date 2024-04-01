#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0), ios::sync_with_stdio(0);
    
    int N;
    string s;
    cin >> s >> s;

    int result = 0, before_g = 0, after_g = 0;

    for (int i = 0; i < N; i++)
        if (s[i] == 'A') after_g++;
        if (s[i] == 'G') {
            before_g += after_g;
            after_g = 0;
        }
        if (s[i] == 'T') {
            result += before_g;
        }
    }

    cout << result;
}
