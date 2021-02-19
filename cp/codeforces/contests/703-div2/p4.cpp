#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool pos(vector<int> &arr, vector<int> &pre, vector<int> &pmn, int n, int k, int x)
{
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] >= x)
            pre[i] = 1;
        else
            pre[i] = -1;
        pre[i] += pre[i - 1];
    }
    for (int i = 1; i <= n; i++)
        pmn[i] = min(pmn[i - 1], pre[i]);
    for (int i = k; i <= n; i++)
        if (pre[i] > pmn[i - k])
            return true;
    return false;
}

int solve()
{
    int n, k, mn = 2e5 + 5, mx = 0, res = 0;
    cin >> n >> k;
    vector<int> arr(n + 1), pre(n + 1), pmn(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        mn = min(mn, arr[i]);
        mx = max(mx, arr[i]);
    }
    int l = 1, r = n;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (pos(arr, pre, pmn, n, k, mid))
        {
            res = max(res, mid);
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    if (pos(arr, pre, pmn, n, k, l))
        res = max(res, l);
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