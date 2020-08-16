#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

inline int geti() {
    register int ans = 0; register char c = getchar();
    while(c<'0' || '9'<c) c = getchar();
    while('0'<=c&&c<='9') ans = ans *10 + c - '0', c = getchar();
    return ans;
}

const int maxn = (200000 + 8)*2;
int lst[maxn], nxt[maxn], ncnt;
long long v[maxn];

long long inf = 10000000000000000LL;

struct node {
    int id;
    long long val;
};

struct cmp {
    bool operator()(node A, node B) {
        return A.val < B.val;
    }
};

long long ans[maxn];
bool del[maxn];

priority_queue<node, vector<node>, cmp> pq;

void debug() {
    printf("ncnt = %d\n", ncnt);
    for(int i = 1; i <= ncnt; i ++) {
        printf("node[%d] (%d, %d) %lld\n", i, lst[i], nxt[i], v[i]);
    }
}

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out","w",stdout);
    int n = geti(); 
    for(int i = 1; i <= n; i ++) {
        v[i] = geti();
        lst[i] = i-1;
        nxt[i] = i+1;
        pq.push((node){i, v[i]});
    }
    lst[1] = n + 1; nxt[n + 1] = 1;
    nxt[n] = n + 1; lst[n + 1] = n;
    pq.push((node){n+1, -inf});
    v[n+1] = -inf;
    ncnt = n + 1;

    long long sum = 0;
    //printf("input end.\n");

    for(int tt = 1; tt <= (n+1)/2; tt ++) {
        node tmp = pq.top(); pq.pop();
        if(del[tmp.id]) {
            tt --;
            continue;
        }
        int x = tmp.id, L = lst[x], R = nxt[x];
        del[x] = del[L] = del[R] = true;
        int LL = lst[L], RR = nxt[R];

        int nn = ++ ncnt; /// newnode
        nxt[LL] = nn; lst[nn] = LL;
        lst[RR] = nn; nxt[nn] = RR;
        v[nn] = v[L] + v[R] - v[tmp.id];
        pq.push((node){nn, v[nn]}); 

        sum += tmp.val;
        printf("%lld\n", sum);
        //debug();
    }
    return 0;
}