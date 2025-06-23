#include <stdio.h>

const int MAXN = 1e6 + 1;

int n, a[MAXN], mem[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    puts("");

    return 0;
}
