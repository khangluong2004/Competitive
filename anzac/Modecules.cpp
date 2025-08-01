#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <algorithm>
#include <chrono>
#include <cmath>
#include <complex>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long i64;
typedef long double f64;
typedef vector<i64> v64;
typedef vector<int> v32;
f64 eps = 1e-12;

#define print(x) cout << #x << " = " << x << '\n'
#define MAX 2e18
#define MIN -2e18
#define fast_cin()                                                                                                     \
    ios_base::sync_with_stdio(false);                                                                                  \
    cin.tie(NULL);                                                                                                     \
    cout.tie(NULL)
using namespace std;
#define lint long long
const int MAXN = 2000;
const lint inf = 1e9;
struct Dinic
{
    struct Edge
    {
        int from, to;
        long long flow, cap;
        Edge(int _from, int _to, long long _flow, long long _cap) : from(_from), to(_to), flow(_flow), cap(_cap) {}
    };
    int N;
    vector<Edge> edges;
    vector<vector<int>> adj;
    vector<vector<int>::iterator> cur;
    void reset()
    {
        // cur.clear();
        edges.clear();
        for (int i = 0; i < N; i++)
            adj[i].clear();
    }
    void init(int _N)
    {
        N = _N;
        adj.resize(N);
        cur.resize(N);
    }
    vector<int> dist;
    void addEdge(int u, int v, long long flow)
    {
        adj[u].push_back(edges.size());
        edges.push_back(Edge(u, v, 0, flow));
        adj[v].push_back(edges.size());
        edges.push_back(Edge(v, u, 0, 0));
    }
    bool bfs(int s, int t)
    {
        dist = vector<int>(N, -1);
        queue<int> q;
        q.push(s);
        dist[s] = 0;
        for (int i = 0; i < N; i++)
            cur[i] = adj[i].begin();
        while (q.size())
        {
            int node = q.front();
            q.pop();
            for (int i = 0; i < adj[node].size(); i++)
            {
                const Edge &E = edges[adj[node][i]];
                int v = E.to;
                if (dist[v] < 0 && E.flow < E.cap)
                {
                    dist[v] = dist[node] + 1;
                    q.push(v);
                }
            }
        }
        return dist[t] + 1 > 0;
    }
    long long dfs(int s, int t, long long flow)
    {
        if (s == t)
            return flow;
        for (; cur[s] != adj[s].end(); cur[s]++)
        {
            Edge &E = edges[*cur[s]];
            if (dist[E.to] != dist[s] + 1 || E.flow == E.cap)
                continue;
            long long df = dfs(E.to, t, min(flow, E.cap - E.flow));
            if (df)
            {
                E.flow += df;
                edges[*cur[s] xor 1].flow -= df;
                return df;
            }
        }
        return 0;
    }
    long long maxflow(int s, int t)
    {
        long long ans = 0;
        while (bfs(s, t))
        {
            while (long long df = dfs(s, t, inf))
            {
                ans += df;
            }
        }
        return ans;
    }
};
int n, m;
int to(int i, int j)
{
    return (i - 1) * m + j;
}
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char g[MAXN][MAXN];
bool valid(int i, int j)
{
    return (1 <= i && i <= n && 1 <= j && j <= m && g[i][j] != '.');
}
signed main(void)
{
    cin >> n >> m;
    // Maximum cardinality matching (Pairity : sum(i + j) % 2 == 0 ? )
    Dinic dinic;
    dinic.init(n * m + 2);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
        }
    }
    int src = 0, sink = n * m + 1;
    map<char, int> fl;
    fl['C'] = 4;
    fl['N'] = 3;
    fl['O'] = 2;
    fl['H'] = 1;
    int even, odd = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (g[i][j] == '.')
                continue;
            if ((i + j) % 2 == 0)
            {
                dinic.addEdge(src, to(i, j), fl[g[i][j]]);
                even += fl[g[i][j]];
                for (int k = 0; k < 4; k++)
                {
                    int px = i + dx[k];
                    int py = j + dy[k];
                    if (valid(px, py))
                    {
                        dinic.addEdge(to(i, j), to(px, py), 1);
                    }
                }
            }
            else
            {
                odd += fl[g[i][j]];
                dinic.addEdge(to(i, j), sink, fl[g[i][j]]);
            }
        }
    }
    lint res = dinic.maxflow(src, sink);
    if (res == even && res == odd)
    {
        puts("Valid");
    }
    else
    {
        puts("Invalid");
    }
    return 0;
}