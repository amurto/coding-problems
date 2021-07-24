#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    vector<int> ids(n);
    iota(ids.begin(), ids.end(), 0);
    vector<vector<int>> st(n, vector<int>(5));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (char ch : arr[i])
            st[i][ch - 'a']++;
    }
    int mx = 0;
    for (int c = 0; c < 5; c++)
    {
        vector<int> d(n);
        for (int i = 0; i < n; i++)
        {
            d[i] += 2 * st[i][c];
            d[i] -= arr[i].size();
        }
        sort(ids.begin(), ids.end(), [&](int &i1, int &i2)
             { return d[i1] > d[i2]; });
        int cur = 0;
        for (int i = 0; i < n; i++)
        {
            cur += d[ids[i]];
            if (cur > 0)
                mx = max(mx, i + 1);
        }
    }
    return mx;
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