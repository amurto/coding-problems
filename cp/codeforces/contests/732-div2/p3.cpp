#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    map<int, int> mp0, mp1;
    for (int i = 0; i < n; i++)
        if (i & 1)
            mp1[arr[i]]++;
        else
            mp0[arr[i]]++;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
        if (i & 1)
            mp1[arr[i]]--;
        else
            mp0[arr[i]]--;
    for (auto x : mp0)
        if (x.second != 0)
            return false;
    for (auto x : mp1)
        if (x.second != 0)
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}