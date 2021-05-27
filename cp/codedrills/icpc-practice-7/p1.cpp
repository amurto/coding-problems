#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    for (auto x : mp)
    {
        if (m == 0)
            break;
        if (m < x.second)
        {
            if (arr[0] == x.first)
                return "MAYBE";
            m = 0;
        }
        else
        {
            if (arr[0] <= x.first)
                return "YES";
            m -= x.second;
        }
    }
    return "NO";
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