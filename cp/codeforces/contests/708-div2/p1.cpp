#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int f(vector<int> &mp)
{
    for (int i = 0; i <= 100; i++)
        if (mp[i] == 0)
            return i;
    return 101;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), mp(101), b;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    int mex = f(mp);
    for (int i = 0; i < mex; i++)
    {
        b.pb(i);
        mp[i]--;
    }
    for (int i = 0; i <= 100; i++)
    {
        while (mp[i] > 0)
        {
            b.pb(i);
            mp[i]--;
        }
    }
    for (int x : b)
        cout << x << " ";
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