// https://codeforces.com/contest/742/problem/C
// Arpa's loud Owf and Mehrdad's evil plan

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int lcm(vector<int> &e)
{
    int res = e[0];
    for (int i = 1; i < e.size(); i++)
        res = (res * e[i]) / __gcd(res, e[i]);
    return res;
}

int dfs(vector<int> &arr, vector<int> &vis, int root, int cur, int len)
{
    if (cur == root)
        return len + 1;
    if (vis[cur])
        return -1;
    vis[cur] = 1;
    return dfs(arr, vis, root, arr[cur], len + 1);
}

int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1), vis(n + 1), e;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 1)
            continue;
        int r = dfs(arr, vis, i, arr[i], 0);
        if (r == -1)
            return -1;
        if (r % 2 == 0)
            r /= 2;
        e.pb(r);
    }
    return lcm(e);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}