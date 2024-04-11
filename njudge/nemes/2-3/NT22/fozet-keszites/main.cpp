#include <bits/stdc++.h>
using namespace std;

const vector<vector<int>> facts
{
    {},
	{},
	{2},
	{3},
	{2},
	{5},
	{2, 3},
	{7},
	{2},
	{3},
	{2, 5},
	{11},
	{2, 3},
	{13},
	{2, 7},
	{3, 5},
	{2},
	{17},
	{2, 3},
	{19},
	{2, 5},
	{3, 7},
	{2, 11},
	{23},
	{2, 3},
	{5},
	{2, 13},
	{3},
	{2, 7},
	{29},
	{2, 3, 5},
	{31},
	{2},
	{3, 11},
	{2, 17},
	{5, 7},
	{2, 3},
	{37},
	{2, 19},
	{3, 13},
	{2, 5},
	{41},
	{2, 3, 7},
	{43},
	{2, 11},
	{3, 5},
	{2, 23},
	{47},
	{2, 3},
	{7},
	{2, 5},
	{3, 17},
	{2, 13},
	{53},
	{2, 3},
	{5, 11},
	{2, 7},
	{3, 19},
	{2, 29},
	{59},
	{2, 3, 5},
	{61},
	{2, 31},
	{3, 7},
	{2},
	{5, 13},
	{2, 3, 11},
	{67},
	{2, 17},
	{3, 23},
	{2, 5, 7},
	{71},
	{2, 3},
	{73},
	{2, 37},
	{3, 5},
	{2, 19},
	{7, 11},
	{2, 3, 13},
	{79},
	{2, 5},
	{3},
	{2, 41},
	{83},
	{2, 3, 7},
	{5, 17},
	{2, 43},
	{3, 29},
	{2, 11},
	{89},
	{2, 3, 5},
	{7, 13},
	{2, 23},
	{3, 31},
	{2, 47},
	{5, 19},
	{2, 3},
	{97},
	{2, 7},
	{3, 11},
	{2, 5},
	{101},
	{2, 3, 17},
	{103},
	{2, 13},
	{3, 5, 7},
	{2, 53},
	{107},
	{2, 3},
	{109},
	{2, 5, 11},
	{3, 37},
	{2, 7},
	{113},
	{2, 3, 19},
	{5, 23},
	{2, 29},
	{3, 13},
	{2, 59},
	{7, 17},
	{2, 3, 5},
	{11},
	{2, 61},
	{3, 41},
	{2, 31},
	{5},
	{2, 3, 7},
	{127},
	{2},
	{3, 43},
	{2, 5, 13},
	{131},
	{2, 3, 11},
	{7, 19},
	{2, 67},
	{3, 5},
	{2, 17},
	{137},
	{2, 3, 23},
	{139},
	{2, 5, 7},
	{3, 47},
	{2, 71},
	{11, 13},
	{2, 3},
	{5, 29},
	{2, 73},
	{3, 7},
	{2, 37},
	{149},
	{2, 3, 5},
	{151},
	{2, 19},
	{3, 17},
	{2, 7, 11},
	{5, 31},
	{2, 3, 13},
	{157},
	{2, 79},
	{3, 53},
	{2, 5},
	{7, 23},
	{2, 3},
	{163},
	{2, 41},
	{3, 5, 11},
	{2, 83},
	{167},
	{2, 3, 7},
	{13},
	{2, 5, 17},
	{3, 19},
	{2, 43},
	{173},
	{2, 3, 29},
	{5, 7},
	{2, 11},
	{3, 59},
	{2, 89},
	{179},
	{2, 3, 5},
	{181},
	{2, 7, 13},
	{3, 61},
	{2, 23},
	{5, 37},
	{2, 3, 31},
	{11, 17},
	{2, 47},
	{3, 7},
	{2, 5, 19},
	{191},
	{2, 3},
	{193},
	{2, 97},
	{3, 5, 13},
	{2, 7},
	{197},
	{2, 3, 11},
	{199},
	{2, 5},
	{3, 67},
	{2, 101},
	{7, 29},
	{2, 3, 17},
	{5, 41},
	{2, 103},
	{3, 23},
	{2, 13},
	{11, 19},
	{2, 3, 5, 7},
	{211},
	{2, 53},
	{3, 71},
	{2, 107},
	{5, 43},
	{2, 3},
	{7, 31},
	{2, 109},
	{3, 73},
	{2, 5, 11},
	{13, 17},
	{2, 3, 37},
	{223},
	{2, 7},
	{3, 5},
	{2, 113},
	{227},
	{2, 3, 19},
	{229},
	{2, 5, 23},
	{3, 7, 11},
	{2, 29},
	{233},
	{2, 3, 13},
	{5, 47},
	{2, 59},
	{3, 79},
	{2, 7, 17},
	{239},
	{2, 3, 5},
	{241},
	{2, 11},
	{3},
	{2, 61},
	{5, 7},
	{2, 3, 41},
	{13, 19},
	{2, 31},
	{3, 83},
	{2, 5},
	{251},
	{2, 3, 7},
	{11, 23},
	{2, 127},
	{3, 5, 17},
	{2},
	{257},
	{2, 3, 43},
	{7, 37},
	{2, 5, 13},
	{3, 29},
	{2, 131},
	{263},
	{2, 3, 11},
	{5, 53},
	{2, 7, 19},
	{3, 89},
	{2, 67},
	{269},
	{2, 3, 5},
	{271},
	{2, 17},
	{3, 7, 13},
	{2, 137},
	{5, 11},
	{2, 3, 23},
	{277},
	{2, 139},
	{3, 31},
	{2, 5, 7},
	{281},
	{2, 3, 47},
	{283},
	{2, 71},
	{3, 5, 19},
	{2, 11, 13},
	{7, 41},
	{2, 3},
	{17},
	{2, 5, 29},
	{3, 97},
	{2, 73},
	{293},
	{2, 3, 7},
	{5, 59},
	{2, 37},
	{3, 11},
	{2, 149},
	{13, 23},
	{2, 3, 5},
	{7, 43},
	{2, 151},
	{3, 101},
	{2, 19},
	{5, 61},
	{2, 3, 17},
	{307},
	{2, 7, 11},
	{3, 103},
	{2, 5, 31},
	{311},
	{2, 3, 13},
	{313},
	{2, 157},
	{3, 5, 7},
	{2, 79},
	{317},
	{2, 3, 53},
	{11, 29},
	{2, 5},
	{3, 107},
	{2, 7, 23},
	{17, 19},
	{2, 3},
	{5, 13},
	{2, 163},
	{3, 109},
	{2, 41},
	{7, 47},
	{2, 3, 5, 11},
	{331},
	{2, 83},
	{3, 37},
	{2, 167},
	{5, 67},
	{2, 3, 7},
	{337},
	{2, 13},
	{3, 113},
	{2, 5, 17},
	{11, 31},
	{2, 3, 19},
	{7},
	{2, 43},
	{3, 5, 23},
	{2, 173},
	{347},
	{2, 3, 29},
	{349},
	{2, 5, 7},
	{3, 13},
	{2, 11},
	{353},
	{2, 3, 59},
	{5, 71},
	{2, 89},
	{3, 7, 17},
	{2, 179},
	{359},
	{2, 3, 5},
	{19},
	{2, 181},
	{3, 11},
	{2, 7, 13},
	{5, 73},
	{2, 3, 61},
	{367},
	{2, 23},
	{3, 41},
	{2, 5, 37},
	{7, 53},
	{2, 3, 31},
	{373},
	{2, 11, 17},
	{3, 5},
	{2, 47},
	{13, 29},
	{2, 3, 7},
	{379},
	{2, 5, 19},
	{3, 127},
	{2, 191},
	{383},
	{2, 3},
	{5, 7, 11},
	{2, 193},
	{3, 43},
	{2, 97},
	{389},
	{2, 3, 5, 13},
	{17, 23},
	{2, 7},
	{3, 131},
	{2, 197},
	{5, 79},
	{2, 3, 11},
	{397},
	{2, 199},
	{3, 7, 19},
	{2, 5},
	{401},
	{2, 3, 67},
	{13, 31},
	{2, 101},
	{3, 5},
	{2, 7, 29},
	{11, 37},
	{2, 3, 17},
	{409},
	{2, 5, 41},
	{3, 137},
	{2, 103},
	{7, 59},
	{2, 3, 23},
	{5, 83},
	{2, 13},
	{3, 139},
	{2, 11, 19},
	{419},
	{2, 3, 5, 7},
	{421},
	{2, 211},
	{3, 47},
	{2, 53},
	{5, 17},
	{2, 3, 71},
	{7, 61},
	{2, 107},
	{3, 11, 13},
	{2, 5, 43},
	{431},
	{2, 3},
	{433},
	{2, 7, 31},
	{3, 5, 29},
	{2, 109},
	{19, 23},
	{2, 3, 73},
	{439},
	{2, 5, 11},
	{3, 7},
	{2, 13, 17},
	{443},
	{2, 3, 37},
	{5, 89},
	{2, 223},
	{3, 149},
	{2, 7},
	{449},
	{2, 3, 5},
	{11, 41},
	{2, 113},
	{3, 151},
	{2, 227},
	{5, 7, 13},
	{2, 3, 19},
	{457},
	{2, 229},
	{3, 17},
	{2, 5, 23},
	{461},
	{2, 3, 7, 11},
	{463},
	{2, 29},
	{3, 5, 31},
	{2, 233},
	{467},
	{2, 3, 13},
	{7, 67},
	{2, 5, 47},
	{3, 157},
	{2, 59},
	{11, 43},
	{2, 3, 79},
	{5, 19},
	{2, 7, 17},
	{3, 53},
	{2, 239},
	{479},
	{2, 3, 5},
	{13, 37},
	{2, 241},
	{3, 7, 23},
	{2, 11},
	{5, 97},
	{2, 3},
	{487},
	{2, 61},
	{3, 163},
	{2, 5, 7},
	{491},
	{2, 3, 41},
	{17, 29},
	{2, 13, 19},
	{3, 5, 11},
	{2, 31},
	{7, 71},
	{2, 3, 83},
	{499},
	{2, 5}
};

const vector<int> primes {
	2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
	101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
	211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293,
	307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397,
	401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499
};

pair<int, int> simplify(int a, int b) {
	for (int prime : primes) {
		
	}
	return {a, b};
}

void solve() {
    int A, B;
    cin >> A >> B;
    unsigned long long result = 0;

    //cout << result << '\n';
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
