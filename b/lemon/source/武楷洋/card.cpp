#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef long long LL;

const int MAX_N = 2000 + 10;

int n;
LL A[MAX_N], fm[1005][MAX_N], ans[1005];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &A[i]);
    }

    for (int i = 1; i <= n; i++) {
        fm[1][i] = A[i];

        for (int k = 1; k <= (n + 1) / 2; k++) {
            for (int j = i - 1; j > 0 && i - j >= 1; j--) {
                fm[k][i] = max(fm[k][i], fm[k - 1][j - 1] + A[i]);
            }
        }
        for (int k = 1; k <= (n + 1) / 2; k++) {
            ans[k] = max(ans[k], fm[k][i]);
        }
    }

    for (int i = 1; i <= (n + 1) / 2; i++) {
        printf("%lld\n", ans[i]);
    }

    return 0;
}