// https://atcoder.jp/contests/dp/tasks/dp_u

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

vector<vector<int>> group(16);

ll grouping(vector<vector<ll>> &a, int cur, int n)
{
    if (cur == n)
        return 0;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        ll temp = 0;
        for (int j = 0; j < group[i].size(); j++)
            temp += a[cur][j];
        group[i].pb(cur);
        sum = max(sum, temp + grouping(a, cur + 1, n));
        group[i].pop_back();
    }
    return sum;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    cout << grouping(a, 0, n) << "\n";
    return 0;
}