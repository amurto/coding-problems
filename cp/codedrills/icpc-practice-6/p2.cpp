#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5;
// O(n)
vector<int> lp(N + 1), mask(N + 1, 1), pr;
void linear_sieve()
{
    for (int i = 2; i <= N; i++)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
    for (int i = 2; i <= N; i++)
    {
        int z = i;
        while (z > 1)
        {
            int d = lp[z], cnt = 0;
            while (z % d == 0)
            {
                cnt ^= 1;
                z /= d;
            }
            if (cnt == 1)
                mask[i] *= d;
        }
    }
}

bool solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    vector<vector<int>> id(n + 1), mp(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        id[mask[i]].pb(i);
        mp[mask[i]].pb(arr[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(mp[i].begin(), mp[i].end());
        for (int j = 0; j < id[i].size(); j++)
            arr[id[i][j]] = mp[i][j];
    }
    return is_sorted(arr.begin(), arr.end());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    linear_sieve();
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}