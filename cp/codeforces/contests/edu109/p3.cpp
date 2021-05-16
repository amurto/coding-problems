#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, pair<int, char>> robot;
#define pb push_back

void op(vector<int> &res, vector<robot> &st, int m)
{
    vector<robot> lbot, rbot;
    stack<robot> bots;
    for (robot r : st)
    {
        if (r.second.second == 'L')
        {
            if (bots.empty())
                lbot.pb(r);
            else
            {
                res[r.first] = abs(r.second.first - bots.top().second.first) / 2;
                res[bots.top().first] = res[r.first];
                bots.pop();
            }
        }
        else
            bots.push(r);
    }
    while (!bots.empty())
    {
        rbot.pb(bots.top());
        bots.pop();
    }
    for (int i = 1; i < lbot.size(); i += 2)
        res[lbot[i - 1].first] = res[lbot[i].first] = lbot[i - 1].second.first + abs(lbot[i - 1].second.first - lbot[i].second.first) / 2;
    for (int i = 1; i < rbot.size(); i += 2)
        res[rbot[i - 1].first] = res[rbot[i].first] = m - rbot[i - 1].second.first + abs(rbot[i - 1].second.first - rbot[i].second.first) / 2;
    int sz1 = lbot.size(), sz2 = rbot.size();
    if ((sz1 & 1) && (sz2 & 1))
    {
        robot l = lbot.back(), r = rbot.back();
        int t = min(l.second.first, m - r.second.first);
        l.second.first -= t;
        r.second.first += t;
        if (l.second.first == 0)
            t += m - r.second.first + abs(r.second.first - l.second.first) / 2;
        else
            t += l.second.first + abs(r.second.first - l.second.first) / 2;
        res[l.first] = res[r.first] = t;
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<robot> arr(n);
    vector<int> res(n, -1);
    for (int i = 0; i < n; i++)
    {
        arr[i].first = i;
        cin >> arr[i].second.first;
    }
    for (int i = 0; i < n; i++)
        cin >> arr[i].second.second;
    sort(arr.begin(), arr.end(), [&](robot &b1, robot &b2)
         { return b1.second.first < b2.second.first; });
    vector<vector<robot>> st(2);
    for (robot r : arr)
        st[r.second.first % 2].pb(r);
    for (int i = 0; i < 2; i++)
        op(res, st[i], m);
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}