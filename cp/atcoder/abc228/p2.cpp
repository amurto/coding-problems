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

int solve()
{
    int n, x, res = 1;
    cin >> n >> x;
    vector<int> arr(n + 1), vis(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    queue<int> q;
    vis[x] = 1;
    q.push(x);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (!vis[arr[cur]])
        {
            vis[arr[cur]] = 1;
            q.push(arr[cur]);
            res++;
        }
    }
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