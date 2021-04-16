#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back

pii get_range(vector<ll> &pre, vector<ll> &suf, ll l, ll r, int n, int m)
{
    ll sum = pre[n - 1];
    if (m == 0)
        return {sum, sum};
    return {sum + l * m - suf[m - 1], sum + r * m - pre[m - 1]};
}

bool merge_range(vector<vector<ll>> &pre, vector<vector<ll>> &suf, ll l, ll r, int n, int k, int m)
{
    pii cur = {1, 1e18};
    for (int i = 0; i < k; i++)
    {
        pii rg = get_range(pre[i], suf[i], l, r, n, m);
        if (rg.first > cur.second || rg.second < cur.first)
            return false;
        cur = {max(cur.first, rg.first), min(cur.second, rg.second)};
    }
    return true;
}

int solve()
{
    int k, n;
    ll l, r;
    cin >> k >> n >> l >> r;
    vector<vector<ll>> arr(k, vector<ll>(n)), pre(k, vector<ll>(n)), suf(k, vector<ll>(n));
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
        sort(arr[i].begin(), arr[i].end());
        pre[i][0] = arr[i][0];
        for (int j = 1; j < n; j++)
            pre[i][j] = pre[i][j - 1] + arr[i][j];
        reverse(arr[i].begin(), arr[i].end());
        suf[i][0] = arr[i][0];
        for (int j = 1; j < n; j++)
            suf[i][j] = suf[i][j - 1] + arr[i][j];
    }
    int low = 0, high = n, res = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        bool f = merge_range(pre, suf, l, r, n, k, mid);
        if (f)
        {
            res = min(res, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
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