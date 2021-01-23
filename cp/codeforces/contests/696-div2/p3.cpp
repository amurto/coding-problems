#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool op(vector<int> &arr, int x)
{
    int tmp = x;
    multiset<int> ms(arr.begin(), arr.end());
    vector<pair<int, int>> res;
    while (!ms.empty())
    {
        int last = *ms.rbegin();
        ms.erase(--ms.end());
        if (last >= x || ms.find(x - last) == ms.end())
            return false;
        ms.erase(ms.lower_bound(x - last));
        res.pb({last, x - last});
        x = last;
    }
    cout << "YES\n"
         << tmp << "\n";
    for (pair<int, int> r : res)
        cout << r.first << " " << r.second << "\n";
    return true;
}
void solve()
{
    int n;
    cin >> n;
    int sz = 2 * n;
    vector<int> arr(sz);
    for (int i = 0; i < sz; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    for (int i = sz - 2; i >= 0; i--)
        if (op(arr, arr[sz - 1] + arr[i]))
            return;
    cout << "NO\n";
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