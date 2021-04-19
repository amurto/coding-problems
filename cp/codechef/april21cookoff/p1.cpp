#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n), tmp;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    for (auto e : mp)
        tmp.pb(e.second);
    sort(tmp.rbegin(), tmp.rend());
    int d = tmp.size();
    for (int i = 0; x > 0 && i < d; i++)
        x -= tmp[i] - 1;
    if (x > 0)
        return d - x;
    return d;
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