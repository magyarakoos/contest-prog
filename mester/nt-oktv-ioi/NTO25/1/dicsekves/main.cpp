#include <iostream>

using namespace std;

int N, psg, psa, mxg, mxa;
int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        char C;
        cin >> C;
        if (C == 'G') {
            psg++;
        } else if (C == 'A') {
            psa++;
        }

        cout << psg - mxg << "-" << psa - mxa << "\n";

        if (mxg - mxa >= psg - psa) {
            mxg = psg;
            mxa = psa;
        }
    }
}
