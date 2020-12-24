// https://codeforces.com/contest/75/problem/B
// Facetook Priority Wall

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool cmp(pair<int, string> &p1, pair<int, string> &p2) {
    if (p1.first == p2.first) 
        return p1.second <= p2.second;
    return p1.first > p2.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    string user, s;
    unordered_map<string, int> mp;
    cin >> user >> n;
    while (n-- > 0)
    {
        string from, action, filler, to;
        cin >> from >> action;
        int score = 0;
        if (action[0] == 'p')
            score = 15;
        else if (action[0] == 'c')
            score = 10;
        else
            score = 5;
        if (action[0] != 'l')
            cin >> filler;
        cin >> to >> filler;
        to = to.substr(0, to.size() - 2);
        if (from != user && mp.find(from) == mp.end())
            mp[from] = 0;
        if (to != user && mp.find(to) == mp.end())
            mp[to] = 0;
        if (from == user)
            mp[to] += score;
        if (to == user)
            mp[from] += score;
    }
    vector<pair<int, string>> res;
    for (auto x : mp)
        res.pb({x.second, x.first});
    sort(res.begin(), res.end(), cmp);
    for (pair<int, string> p : res)
        cout << p.second << "\n";
    return 0;
}