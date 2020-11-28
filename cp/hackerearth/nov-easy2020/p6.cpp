// https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/practice-problems/algorithm/choose-one-c4672347/
// Friendly Neighbors

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, pair<int, int>> piii;
#define pb push_back

int solve()
{
    int n, k, s;
    cin >> n;
    vector<vector<pair<int, int>>> house(n);
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        while (k-- > 0)
        {
            cin >> s;
            house[i].pb({s, i});
        }
        sort(house[i].begin(), house[i].end());
    }

    set<piii> SET;
    for (int i = 0; i < n; i++)
        SET.insert({house[i][0].first, {house[i][0].second, 0}});
    
    int cost = INT_MAX;
    while (SET.size() == n) {
        cost = min(cost, SET.rbegin()->first - SET.begin()->first);
        int cur = SET.begin()->second.first, idx = SET.begin()->second.second;
        SET.erase(SET.begin());
        if (house[cur].size() - 1 > idx) 
            SET.insert({house[cur][idx+1].first, {house[cur][idx+1].second, idx+1}});
    }
    return cost*2;
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
        cout << solve() << "\n";
    }
    return 0;
}