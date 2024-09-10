#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<string> a(N);
    for (string& s : a) cin >> s;
    sort(a.begin(), a.end(),
         [](const string& s, const string& t) { return s + t > t + s; });

    vector<string> dp(K, string(50, 'z'));

    // knapsack
}
