#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    
    int result = 0;
    
    if (A < B) {
        result = B - A + 1;
    }
    else if (A > B) {
        result = N - A + B + 1;
    }

    cout << (result > 4 ? to_string(result) : "Tul konnyu!") << endl;
}
