#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// swaps is n*(n-1)/2
void solve()
{
    int n, cur = 1;
    cin >> n;
    vector<int> arr(n + 1), op;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    while (!is_sorted(arr.begin(), arr.end()))
    {
        // for (int i = 1; i <= n; i++)
        //     cout << arr[i] << " ";
        // cout << "\n";
        vector<vector<int>> req(2);
        vector<int> fix;
        for (int i = 2; i <= n; i++)
        {
            if (i - 1 < arr[i - 1] || i > arr[i])
                req[(i - 1) & 1].pb(i - 1);
            if (i - 1 == arr[i - 1] && i == arr[i])
                fix.pb(i - 1);
        }
        if (req[cur].empty())
        {
            swap(arr[fix[0]], arr[fix[0] + 1]);
            op.pb(fix[0]);
        }
        else
        {
            sort(req[cur].begin(), req[cur].end(), [&](int &i1, int &i2)
                 { return arr[i1 + 1] < arr[i2 + 1]; });
            swap(arr[req[cur][0]], arr[req[cur][0] + 1]);
            op.pb(req[cur][0]);
        }
        cur ^= 1;
    }
    cout << op.size() << "\n";
    for (int e : op)
        cout << e << " ";
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