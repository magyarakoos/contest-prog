#include <bits/stdc++.h>
#include <debug.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<string> a(N);
    for (string& s : a) cin >> s;
    sort(a.begin(), a.end(),
         [](const string& s, const string& t) { return s + t > t + s; });

    vector dp(K, vector<string>(K));
}
