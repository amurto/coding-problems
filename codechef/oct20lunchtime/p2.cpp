// SUBMEXS

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

pair<ll, ll> dfs(int cur, vector<vector<int>> &tree)
{
    // base case
    if (tree[cur].empty())
        return {1, 1};

    ll mex = 0, subtree_size = 1;
    for (int child : tree[cur])
    {
        pair<ll, ll> res = dfs(child, tree);
        mex = max(mex, res.second);
        subtree_size += res.first;
    }
    mex += subtree_size;
    return {subtree_size, mex};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, p;
        cin >> n;
        vector<vector<int>> tree(n + 1);
        for (int i = 1; i <= n - 1; i++)
        {
            cin >> p;
            tree[p].pb(i + 1);
        }
        pair<ll, ll> ans = dfs(1, tree);
        cout << ans.second << "\n";
    }
    return 0;
}