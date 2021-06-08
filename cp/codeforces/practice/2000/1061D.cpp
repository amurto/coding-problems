// https://codeforces.com/contest/1061/problem/D
// TV Shows

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int MOD = 1e9 + 7;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

int solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<pii> arr(n);
    vector<int> prev(n, -1);
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());
    multiset<int> ms;
    for (int i = 0; i < n; i++)
    {
        if (!ms.empty())
        {
            auto it = ms.lower_bound(arr[i].first);
            if (it != ms.begin())
            {
                it--;
                prev[i] = *it;
                ms.erase(it);
            }
        }
        ms.insert(arr[i].second);
    }
    int res = 0, req = (x + y - 1) / y;
    for (int i = 0; i < n; i++)
    {
        if (prev[i] == -1)
            res = add(res, x);
        else
        {
            int d = arr[i].first - prev[i];
            if (d >= req)
                res = add(res, x);
            else
                res = add(res, mul(y, d));
        }
        res = add(res, mul(y, arr[i].second - arr[i].first));
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}