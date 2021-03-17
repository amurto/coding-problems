#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i] % m]++;
    }
    int res = 0;
    if (mp[0] > 0)
        res++;
    if (m % 2 == 0 && mp[m / 2] > 0)
        res++;
    for (int i = 1, j = m - 1; i < j; i++, j--)
    {
        int f = mp[i], s = mp[j];
        if (f == 0 || s == 0)
        {
            res += f;
            res += s;
            continue;
        }
        res++;
        res += max(0, max(f, s) - min(f, s) - 1);
    }
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