# Contest Prog

My general template:

```cpp
#include <iostream>
#include <vector>
#include <array>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <queue>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define range(start, exit, incr) for (int i = start; i exit; i incr)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;
using point = array<int, 2>;

int main() {
    speed;
    
    
}
```

Note: some judge environments don't support the `bits/stdc++.h` header, so I generally include the most important ones.
