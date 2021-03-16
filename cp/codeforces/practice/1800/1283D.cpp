// https://codeforces.com/contest/1283/problem/D
// Christmas Trees

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, m;
    ll sum = 0;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    vector<int> diff(m + 5);
    diff[1] += 2;
    diff[m + 1] -= 2;
    for (int i = 0; i < n; i++)
    {
        // left range
        if (i > 0)
        {
            int h = (arr[i] - arr[i - 1] - 1) / 2;
            if (h > 0)
            {
                diff[1]++;
                diff[min(h + 1, m + 1)]--;
            }
        }
        // right range
        if (i < n - 1)
        {
            int h = (arr[i + 1] - arr[i]) / 2;
            if (h > 0)
            {
                diff[1]++;
                diff[min(h + 1, m + 1)]--;
            }
        }
    }
    for (int i = 1; i < m + 5; i++)
        diff[i] += diff[i - 1];
    int req = m;
    for (int i = 1; i < m + 5; i++)
    {
        diff[i] = min(req, diff[i]);
        req -= diff[i];
        sum += diff[i] * 1ll * i;
    }
    vector<int> res;
    for (int i = 1, j = arr[0] - 1; diff[i] > 0; j--, i++)
    {
        diff[i]--;
        res.pb(j);
    }
    for (int i = 1, j = arr[n - 1] + 1; diff[i] > 0; j++, i++)
    {
        diff[i]--;
        res.pb(j);
    }
    for (int idx = 0; idx < n; idx++)
    {
        // left range
        if (idx > 0)
        {
            int h = (arr[idx] - arr[idx - 1] - 1) / 2;
            for (int i = 1, j = arr[idx] - 1; i <= h && diff[i] > 0; j--, i++)
            {
                diff[i]--;
                res.pb(j);
            }
        }
        // right range
        if (idx < n - 1)
        {
            int h = (arr[idx + 1] - arr[idx]) / 2;
            for (int i = 1, j = arr[idx] + 1; i <= h && diff[i] > 0; j++, i++)
            {
                diff[i]--;
                res.pb(j);
            }
        }
    }
    cout << sum << "\n";
    for (int r : res)
        cout << r << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}