#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

inline int geti() {
    register int ans = 0; register char c = getchar(); bool flag = false;
    while(c<'0' || '9'<c) c= getchar(), flag |= c == '-';
    while('0'<=c&&c<='9') ans = ans*10+c-'0', c = getchar();
    return flag? -ans: ans;
}

const int maxn = 200000 + 6, maxm = 400000 + 6;

namespace graph {
    struct edge {
        int t, c, w;
    };
    vector<edge> G[maxn], PRE[maxn];
    void addedge(int f, int t, int c, int w) {
        G  [f].push_back((edge){t, c, w});
        PRE[t].push_back((edge){f, c, w});
    }
    bool vis[maxn]; double dp[maxn]; /// 平均能走出多远
    double sum[maxn]; /// sum for w
    double DP(int x) {
        if(vis[x]) return dp[x];
        vis[x] = true;
        sum[x] = dp[x] = 0;
        for(int i = 0; i < G[x].size(); i ++) {
            edge& e = G[x][i];
            sum[x] += e.w;
        }
        for(int i = 0; i < G[x].size(); i ++) {
            edge& e = G[x][i];
            dp[x] += (DP(e.t) + e.c) * e.w/sum[x];
        }
        return dp[x];
    }

    double P[maxn];
    bool visp[maxn];
    double p(int x) { /// 计算走到某个点的概率
        if(visp[x]) return P[x];
        visp[x] = true;
        if(x == 1) {
            P[x] = 1.0;
        }else {
            for(int i = 0; i < PRE[x].size(); i ++) {
                edge& e = PRE[x][i];
                P[x] += p(e.t) * e.w/sum[e.t]; /// e.w is w/sum[from]
            }
        }
        return P[x];
    }

    double ansnow = 0;
    bool solved[maxn];
    void solve(int x) { /// 考虑删除一条x的出边
        if(solved[x]) return;
        solved[x] = true;
        for(int i = 0; i < G[x].size(); i ++) {
            solve(G[x][i].t);
        }
        for(int i = 0; i < G[x].size(); i ++) { /// 删除 x 的一条出边
            edge& e = G[x][i];
            double ans;
            if(sum[x] > e.w)
                ans = DP(1) - p(x) * DP(x) + p(x) * (DP(x) - e.w/sum[x] * (e.c + DP(e.t)))*sum[x]/(sum[x]-e.w);
            else
                ans = DP(x) - p(x) * DP(x) + p(x) * 0;
            //printf("commit %lf, %d -> %d\n", ans, x, e.t);
            ansnow = min(ansnow, ans);
        }
    }

    void main(int n) {
        for(int i = 1; i <= n; i ++) {
            DP(i); p(i);
        }
        ansnow = DP(1);
        //printf("ansnow = DP(1) = %lf\n", ansnow);
        solve(1);
    }
}

int main() {
    freopen("return.in", "r", stdin);
    freopen("return.out","w",stdout);
    int n = geti(), m = geti();
    for(int i = 1; i <= m; i ++) {
        int u = geti(), v = geti(), w = geti(), l = geti();
        graph::addedge(u, v, l, w);
    }
    graph::main(n);
    printf("%.3lf", graph::ansnow);
    return 0;
}