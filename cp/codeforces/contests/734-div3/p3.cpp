#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n), c(n), f(n + 1);
    vector<vector<int>> ids(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        f[arr[i]]++;
        f[arr[i]] = min(f[arr[i]], k);
        ids[arr[i]].pb(i);
    }
    int sum = 0;
    vector<int> tmp;
    for (int i = 1; i <= n; i++)
    {
        if (f[i] == k)
        {
            for (int j = 0, p = 1; p <= k; j++, p++)
                c[ids[i][j]] = p;
        }
        else
        {
            sum += f[i];
            for (int id : ids[i])
                tmp.pb(id);
        }
    }
    int req = sum / k;
    for (int i = 0, p = 0; i < req * k; i++)
    {
        c[tmp[i]] = p + 1;
        p++;
        p %= k;
    }
    for (int i = 0; i < n; i++)
        cout << c[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}