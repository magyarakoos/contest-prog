#include "aplusb.h"

using namespace std;


std::vector<int> smallest_sums(int N, std::vector<int> A, std::vector<int> B) {

    vector<int> result;

    int i = 0, j = 0;

    for (int k = 0; k < N; k++) {
        result.push_back(A[i] + B[j]);
        if (A[i + 1] < B[j + 1]) i++;
        else j++;
    }

    return result;
}

