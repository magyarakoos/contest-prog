#include <bits/stdc++.h>
using namespace std;

int main() {
    int S, T, result = 0;
    cin >> S >> T;
    for (int a = 0; a <= S; a++) {
        for (int b = 0; b <= S; b++) {
            for (int c = 0; c <= S; c++) {
                result += a + b + c <= S && a * b * c <= T;
            }
        }    
    }
    cout << result;
}
