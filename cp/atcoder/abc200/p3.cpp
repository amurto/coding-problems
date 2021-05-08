#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int, int> mp;
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i] % 200]++;
    }
    for (auto x : mp)
        res += (x.second * 1ll * (x.second - 1)) / 2;
    cout << res << "\n";
    return 0;
}