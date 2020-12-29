#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int vis[5000000];

void solve(int tc)
{
    int n, k;
    string str;
    cin >> n >> k >> str;
    int sz = min(k, 22);
    vector<int> last(n);
    if (str[0] == '0')
        last[0] = 0;
    else
        last[0] = -1;
    for (int i = 1; i < n; i++)
        if (str[i] == '0')
            last[i] = i;
        else
            last[i] = last[i - 1];
    for (int i = 0; i + k - 1 < n; i++)
    {
        int mask = 0;
        for (int j = 0; j < sz; j++)
            if (str[i + k - 1 - j] == '0')
                mask |= (1 << j);
        if (mask == 0)
        {
            int check = i + k - sz - 1;
            // cout << i << " " << check << "\n";
            if (check < i || last[check] >= i)
                vis[mask] = tc;
            continue;
        }
        vis[mask] = tc;
    }
    for (int c = 0; c < (1 << sz); c++)
    {
        if (vis[c] != tc)
        {
            cout << "YES\n";
            for (int i = 0; i < k - sz; i++)
                cout << 0;
            for (int i = sz - 1; i >= 0; i--)
                (c & (1 << i)) ? cout << 1 : cout << 0;
            cout << "\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(vis, 0, sizeof(vis));
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
        solve(tc);
    return 0;
}