#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int N = 1e5 + 5;
int vis[N], mp[N];

void solve(int tc)
{
    int n;
    cin >> n;
    vector<pii> arr(n), res;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
        mp[arr[i].first] = arr[i].second;
        vis[arr[i].first] = tc;
    }
    sort(arr.rbegin(), arr.rend());
    for (int i = 0; i < n; i++)
    {
        if (mp[arr[i].first] <= 0)
            continue;
        res.pb({arr[i].first, mp[arr[i].first]});
        int rem = mp[arr[i].first];
        for (int x = 1; x * x <= arr[i].first; x++)
        {
            if (arr[i].first % x == 0 && vis[x] == tc)
            {
                mp[x] -= rem;
                if (x * x != arr[i].first)
                    mp[arr[i].first / x] -= rem;
            }
        }
    }
    reverse(res.begin(), res.end());
    cout << res.size() << "\n";
    for (pii p : res)
        cout << p.first << " " << p.second << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cout << "Case " << tc << ":\n";
        solve(tc);
    }
    return 0;
}