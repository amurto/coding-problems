#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll dis(int i, int j, vector<int> &arr)
{
    return abs(i - j) + abs(arr[i] - arr[j]);
}

ll solve()
{
    int n;
    cin >> n;
    ll res = 0;
    vector<int> arr(n), l1(n, -1), r1(n, -1), l2(n, -1), r2(n, -1), pre(n, -1);
    // l1 = prev smaller
    // r1 = next greater
    // l2 = next smaller
    // r2 = prev greater
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    stack<int> lst, rst;
    for (int i = 0; i < n; i++)
    {
        while (!lst.empty() && arr[lst.top()] > arr[i])
            lst.pop();
        if (!lst.empty())
            l1[i] = lst.top();
        lst.push(i);
        while (!rst.empty() && arr[rst.top()] < arr[i])
            rst.pop();
        if (!rst.empty())
            r2[i] = rst.top();
        rst.push(i);
    }
    while (!lst.empty())
        lst.pop();
    while (!rst.empty())
        rst.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!lst.empty() && arr[lst.top()] > arr[i])
            lst.pop();
        if (!lst.empty())
            l2[i] = lst.top();
        lst.push(i);
        while (!rst.empty() && arr[rst.top()] < arr[i])
            rst.pop();
        if (!rst.empty())
            r1[i] = rst.top();
        rst.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        if (r1[i] != -1)
            pre[r1[i]] = max(pre[r1[i]], l1[i]);
        if (l2[i] != -1)
            pre[l2[i]] = max(pre[l2[i]], r2[i]);
    }
    for (int i = 1; i < n; i++)
        pre[i] = max(pre[i - 1], pre[i]);
    for (int i = 0; i < n; i++)
        res += 1ll * (i - pre[i]);
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