// https://codeforces.com/contest/479/problem/B
// Towers

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k, v;
    cin >> n >> k;
    multiset<pair<int, int>> ms;
    vector<pair<int, int>> op;
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        ms.insert({v, i});
    }
    int d = ms.rbegin()->first - ms.begin()->first;
    while (k > 0 && d > 1)
    {
        int L = ms.begin()->first, R = ms.rbegin()->first, i = ms.rbegin()->second, j = ms.begin()->second;
        ms.erase(ms.begin());
        auto it = ms.end();
        it--;
        ms.erase(it);
        L++;
        R--;
        ms.insert({L, j});
        ms.insert({R, i});
        op.pb({i, j});
        d = ms.rbegin()->first - ms.begin()->first;
        k--;
    }
    cout << d << " " << op.size() << "\n";
    for (pair<int, int> p : op)
        cout << p.first + 1 << " " << p.second + 1 << "\n";
    return 0;
}