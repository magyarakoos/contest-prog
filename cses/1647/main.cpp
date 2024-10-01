#include <iostream>

using namespace std;

int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

int st[25][200005];
int main() {}

