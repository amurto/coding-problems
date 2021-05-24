#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, res = 1;
    cin >> n;
    vector<int> arr(n), nz, pos;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] <= 0)
            nz.pb(arr[i]);
        else
            pos.pb(arr[i]);
    }
    sort(nz.begin(), nz.end());
    sort(pos.begin(), pos.end());
    int d = 2e9 + 5, sz = nz.size();
    for (int i = 1; i < nz.size(); i++)
        d = min(d, abs(nz[i] - nz[i - 1]));
    res = max(res, sz);
    if (!pos.empty() && pos[0] <= d)
        res = max(res, sz + 1);
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