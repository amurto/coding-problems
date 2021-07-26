#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void dfs(vector<int> &arr, vector<bool> &vis, vector<int> &cnt, int cur, int n)
{
    vis[cur] = true;
    cnt[cur > n]++;
    if (!vis[arr[cur]])
        dfs(arr, vis, cnt, arr[cur], n);
}

int solve()
{
    int n, m;
    ll res = 0;
    cin >> n >> m;
    vector<int> arr(n + m + 1);
    for (int i = 1; i <= n + m; i++)
        cin >> arr[i];
    vector<bool> vis(n + m + 1);
    for (int i = 1; i <= n + m; i++)
        if (i == arr[i])
            vis[i] = true;
    vector<int> tmp(2);
    for (int i = 1; i <= n + m; i++)
    {
        if (!vis[i])
        {
            vector<int> cnt(2);
            dfs(arr, vis, cnt, i, n);
            if (cnt[0] > 0 && cnt[1] > 0)
                res += cnt[0] + cnt[1] - 1;
            else
            {
                res += cnt[0] + cnt[1];
                tmp[0] += (cnt[0] > 0);
                tmp[1] += (cnt[1] > 0);
            }
        }
    }
    if (tmp[0] < tmp[1])
        swap(tmp[0], tmp[1]);
    tmp[0] -= tmp[1];
    res += tmp[0];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}