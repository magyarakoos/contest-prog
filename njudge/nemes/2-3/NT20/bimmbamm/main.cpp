#include <iostream>
#include <string>
using namespace std;
#define speed cin.tie(0); ios::sync_with_stdio(0)

int main() {
    speed;
    
    int N;
    cin >> N;
    string s;
    int i = 1;
    for (int i = 1, found = 0; i <= N; i++) {
        cin >> s;
        if (!found) {
            string correct = (
                i % 3 == 0 && i % 5 == 0 ? "BUMM" : 
                i % 5 == 0 ? "BAMM" : 
                i % 3 == 0 ? "BIMM" : 
                "SZAM"
            );
            if (s != correct) {
                cout << i;
                found = 1;
            }
        }
    }
    
}
