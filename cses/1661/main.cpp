#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, X, result, ps, a;
int main() {
   map<ll, int> m;
   m[0] = 1;
   cin >> N >> X;
   while (N--) {
      cin >> a;
      result += m[(ps += a) - X];
      m[ps]++;
   }
   cout << result;
}
