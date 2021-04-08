// https://codeforces.com/contest/548/problem/D
// Mike and Feet

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n), lb(n), rb(n), unq, res(n + 2);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        unq.pb(arr[i]);
    }
    sort(unq.begin(), unq.end());
    unq.resize(unique(unq.begin(), unq.end()) - unq.begin());
    int sz = unq.size();
    vector<int> dis(sz);
    stack<int> lst, rst;
    for (int i = 0; i < n; i++)
    {
        while (!lst.empty() && arr[lst.top()] >= arr[i])
            lst.pop();
        lb[i] = lst.empty() ? -1 : lst.top();
        lst.push(i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!rst.empty() && arr[rst.top()] >= arr[i])
            rst.pop();
        rb[i] = rst.empty() ? n : rst.top();
        rst.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        int idx = lower_bound(unq.begin(), unq.end(), arr[i]) - unq.begin();
        dis[idx] = max(dis[idx], rb[i] - lb[i] - 1);
    }
    int p = 0;
    for (int i = sz - 1; i >= 0; i--)
    {
        if (dis[i] > p)
        {
            res[p + 1] += unq[i];
            res[dis[i] + 1] -= unq[i];
            p = dis[i];
        }
    }
    for (int i = 1; i < n + 2; i++)
        res[i] += res[i - 1];
    for (int i=1; i<=n; i++)
        cout << res[i] << " ";
    return 0;
}