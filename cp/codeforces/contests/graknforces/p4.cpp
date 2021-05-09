// https://codeforces.com/contest/1408/problem/D
// Searchlights

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int solve()
{
    int n, m, res = 1e9;
    cin >> n >> m;
    vector<pii> rob(n), light(m), seq;
    for (int i = 0; i < n; i++)
        cin >> rob[i].first >> rob[i].second;
    for (int i = 0; i < m; i++)
        cin >> light[i].first >> light[i].second;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (rob[i].first <= light[j].first && rob[i].second <= light[j].second)
                seq.pb({light[j].first - rob[i].first + 1, light[j].second - rob[i].second + 1});
    if (seq.empty())
        return 0;
    sort(seq.begin(), seq.end());
    int sz = seq.size(), suf = 0;
    for (int i = sz - 1; i >= 0; i--)
    {
        res = min(res, seq[i].first + suf);
        suf = max(suf, seq[i].second);
    }
    res = min(res, suf);
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