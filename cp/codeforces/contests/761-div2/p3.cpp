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
    int n, res = 0;
    cin >> n;
    vector<int> arr(n);
    vector<bool> vis(n + 1);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= n && !vis[arr[i]])
            vis[arr[i]] = true;
        else
            pq.push((arr[i] - 1) / 2);
    }
    for (int i = n; i >= 1; i--)
    {
        if (!vis[i])
        {
            if (pq.empty() || pq.top() < i)
                return -1;
            pq.pop();
            res++;
            vis[i] = true;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}