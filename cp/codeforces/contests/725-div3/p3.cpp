#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n, l, r;
    ll res = 0;
    cin >> n >> l >> r;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= r)
            continue;
        int lv = l - arr[i], rv = r - arr[i];
        int rb = upper_bound(arr.begin(), arr.end(), rv) - arr.begin();
        int lb = lower_bound(arr.begin(), arr.end(), lv) - arr.begin();
        res += 1ll * (rb - lb);
        if (2 * arr[i] >= l && 2 * arr[i] <= r)
            res--;
    }
    return res / 2;
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