// https://codeforces.com/contest/141/problem/C
// Queue

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, string>> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i].second >> arr[i].first;
    sort(arr.begin(), arr.end());
    if (arr[0].first > 0)
    {
        cout << "-1\n";
        return;
    }
    vector<pair<int, int>> res;
    res.pb({6000, 0});
    for (int i = 1; i < n; i++)
    {
        int pos = arr[i].first;
        if (pos > res.size())
        {
            cout << "-1\n";
            return;
        }
        pair<int, int> cur = {res[res.size() - 1].first, i};
        if (pos < res.size())
            cur.first = res[pos].first + 1;
        res.insert(res.begin() + pos, cur);
        for (int j = 0; j < pos; j++)
            res[j].first++;
    }
    for (pair<int, int> r : res)
        arr[r.second].first = r.first;
    for (pair<int, string> a : arr)
        cout << a.second << " " << a.first << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}