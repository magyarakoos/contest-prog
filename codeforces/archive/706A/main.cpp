#include <bits/stdc++.h>
using namespace std;
    
int main() {
    double a, b, N, result = 1e9;
    cin >> a >> b >> N;
    
    while (N--) {
        double x, y, v;
        cin >> x >> y >> v;
        result = min(result, sqrt(pow(abs(x - a), 2) + pow(abs(y - b), 2)) / v);
    }
    
    cout << fixed << setprecision(15) << result;
}
