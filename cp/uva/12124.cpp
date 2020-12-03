// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3276
// 12124 - Assemble

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool f(vector<vector<pair<ll, ll>>> &data, ll q, ll b)
{
    for (int i = 0; i < data.size(); i++)
    {
        int low = 0, high = data[i].size() - 1;
        ll c = INT_MAX;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (data[i][mid].first >= q)
            {
                high = mid - 1;
                c = min(c, data[i][mid].second);
            }
            else
            {
                low = mid + 1;
            }
        }
        if (c == INT_MAX)
            return false;
        b -= c;
    }
    return (b >= 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        ll n, b, p, q;
        cin >> n >> b;
        map<string, vector<pair<ll, ll>>> pq;
        string str1, str2;
        for (int i = 0; i < n; i++)
        {
            cin >> str1 >> str2 >> p >> q;
            pq[str1].pb({p, q});
        }
        vector<vector<pair<ll, ll>>> data;
        for (auto x : pq)
        {
            sort(x.second.begin(), x.second.end());
            vector<pair<ll, ll>> arr;
            ll qual = 0;
            for (pair<ll, ll> pr : x.second)
            {
                if (pr.second > qual)
                {
                    qual = pr.second;
                    arr.pb({pr.second, pr.first});
                }
            }
            sort(arr.begin(), arr.end());
            data.pb(arr);
        }
        ll l = 1, r = 1e9;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            if (f(data, mid, b))
                l = mid + 1;
            else
                r = mid - 1;
        }
        cout << r << "\n";
    }

    return 0;
}