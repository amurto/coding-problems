// Maximum Matching in Bipartite Graph
// https://cp-algorithms.com/graph/kuhn_maximum_bipartite_matching.html

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e3 + 5;
vector<int> g[N];
int mt[N];
bool vis[N];

bool try_kuhn(int cur)
{
    if (vis[cur])
        return false;
    vis[cur] = true;
    for (int e : g[cur])
    {
        if (mt[e] == -1 || try_kuhn(mt[e]))
        {
            mt[e] = cur;
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // Divide graph into two parts using Bipartite matching
    vector<int> g1, g2;
    for (int x : g2)
        mt[x] = -1;
    for (int x : g1)
    {
        for (int i : g1)
            vis[i] = false;
        try_kuhn(x);
    }
    return 0;
}