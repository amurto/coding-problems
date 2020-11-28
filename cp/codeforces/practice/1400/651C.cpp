// https://codeforces.com/contest/651/problem/C
// Watchmen

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll countSame(vector<int> arr, int n)
{
    ll p = 0, cnt = 1;
    for (int idx = 1; idx < n; idx++)
    {
        if (arr[idx - 1] == arr[idx])
            cnt++;
        else
        {
            p += cnt * 1ll * (cnt - 1) / 2;
            cnt = 1;
        }
    }
    p += cnt * 1ll * (cnt - 1) / 2;
    return p;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll res = 0, same = 0, cnt = 1;
    cin >> n;
    vector<pair<int, int>> xy(n);
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++)
    {
        cin >> xy[i].first >> xy[i].second;
        x[i] = xy[i].first;
        y[i] = xy[i].second;
    }
    sort(xy.begin(), xy.end());
    for (int idx = 1; idx < n; idx++)
    {
        if (xy[idx - 1].first == xy[idx].first && xy[idx - 1].second == xy[idx].second)
            cnt++;
        else
        {
            same += cnt * 1ll * (cnt - 1) / 2;
            cnt = 1;
        }
    }
    same += cnt * 1ll * (cnt - 1) / 2;
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    res += countSame(x, n) + countSame(y, n) - same;
    cout << res << "\n";
    return 0;
}