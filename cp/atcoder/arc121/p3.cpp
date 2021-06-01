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
        vector<int> req, fix;
        for (int i = 1; i < n; i++)
        {
            if ((i & 1) == cur)
            {
                if (arr[i] > arr[i + 1])
                    req.pb(i);
                else
                    fix.pb(i);
            }
        }
        if (req.empty())
        {
            swap(arr[fix.back()], arr[fix.back() + 1]);
            op.pb(fix.back());
        }
        else
        {
            swap(arr[req[0]], arr[req[0] + 1]);
            op.pb(req[0]);
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