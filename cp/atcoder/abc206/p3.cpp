#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    cin >> n;
    ll res = 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        res += 1ll * (i - mp[arr[i]]);
        mp[arr[i]]++;
    }
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