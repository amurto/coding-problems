// https://codeforces.com/contest/118/problem/C
// Fancy Number

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

vector<pair<int, string>> res;

void op(vector<int> &cnt,
        vector<vector<int>> &st, string str, int target, int n, int k)
{
    int req = k - cnt[target], cost = 0;
    if (req <= 0)
    {
        res.pb({cost, str});
        return;
    }
    auto cmp = [](pii &p1, pii &p2) {
        if (p1.first == p2.first)
            return p2.first < p2.second;
        return p1.first > p2.first;
    };
    priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < 10; i++)
        if (cnt[i] > 0 && i != target)
            pq.push({abs(target - i), i});
    while (req > 0)
    {
        pii tp = pq.top();
        int cur = tp.second;
        pq.pop();
        if (cur < target)
        {
            for (int j = st[cur].size() - 1; req > 0 && j >= 0; j--)
            {
                str[st[cur][j]] = char(target + '0');
                cost += tp.first;
                req--;
            }
        }
        else
        {
            for (int j = 0; req > 0 && j < st[cur].size(); j++)
            {
                str[st[cur][j]] = char(target + '0');
                cost += tp.first;
                req--;
            }
        }
    }
    res.pb({cost, str});
}

void solve()
{
    int n, k;
    string str;
    cin >> n >> k >> str;
    vector<int> cnt(10);
    vector<vector<int>> st(10);
    for (int i = 0; i < n; i++)
    {
        cnt[str[i] - '0']++;
        st[str[i] - '0'].pb(i);
    }
    for (int i = 0; i < 10; i++)
        op(cnt, st, str, i, n, k);
    sort(res.begin(), res.end());
    cout << res[0].first << "\n";
    cout << res[0].second << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}