#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool dfs(vector<int> &arr, vector<bool> &vis, int cur, int sum)
{
    if (cur == arr.size())
    {
        for (int i = 0; i < arr.size(); i++)
            if (!vis[i] && arr[i] == abs(sum))
                return true;
        return false;
    }
    bool ret = false;
    vis[cur] = true;
    ret = (ret || dfs(arr, vis, cur + 1, sum - arr[cur]));
    ret = (ret || dfs(arr, vis, cur + 1, sum + arr[cur]));
    vis[cur] = false;
    ret = (ret || dfs(arr, vis, cur + 1, sum));
    return ret;
}

bool solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i] = abs(arr[i]);
    }
    if (n == 1)
        return arr[0] == 0;
    vector<bool> vis(n);
    return dfs(arr, vis, 0, 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}