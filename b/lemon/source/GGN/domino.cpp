#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    freopen("domino.in", "r", stdin);
    freopen("domino.out","w",stdout);
    int T; scanf("%d", &T);
    while(T --) {
        int n, m; scanf("%d%d", &n, &m);
        printf("%lld\n", ((long long)(n+1))*(m+1)/6);
    }
    return 0;
}