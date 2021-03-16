// https://codeforces.com/contest/1249/problem/D2
// Too Many Segments (hard version)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<pair<int, int>, int> piii;
#define pb push_back

const int N = 2e5 + 5;
queue<int> q[N];

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<piii> p(n);
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first.first >> p[i].first.second;
        p[i].second = i + 1;
    }
    sort(p.begin(), p.end());
    multiset<int> ms;
    for (int i = 0; i < n; i++)
    {
        while (!ms.empty() && *ms.begin() < p[i].first.first)
        {
            q[*ms.begin()].pop();
            ms.erase(ms.begin());
        }
        ms.insert(p[i].first.second);
        q[p[i].first.second].push(p[i].second);
        if (ms.size() > k)
        {
            auto it = --ms.end();
            res.pb(q[*it].front());
            q[*it].pop();
            ms.erase(it);
        }
    }
    cout << res.size() << "\n";
    for (int r : res)
        cout << r << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}