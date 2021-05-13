// https://codeforces.com/contest/1288/problem/D
// Minimax Problem

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int mask(vector<int> &seq, int m, int x)
{
    int cur = 0;
    for (int j = 0; j < m; j++)
        if (seq[j] >= x)
            cur |= (1 << j);
    return cur;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int req = (1 << m) - 1;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    int low = 0, high = 1e9, res = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        vector<int> cnt(1 << m);
        for (int i = 0; i < n; i++)
            cnt[mask(arr[i], m, mid)]++;
        bool f = false;
        for (int i = 0; !f && i < cnt.size(); i++)
            for (int j = 0; !f && j <= i; j++)
                if (cnt[i] > 0 && cnt[j] > 0 && (i | j) == req)
                    f = true;
        if (f)
        {
            res = max(res, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    vector<vector<int>> ids(1 << m);
    for (int i = 0; i < n; i++)
        ids[mask(arr[i], m, res)].pb(i);
    for (int i = 0; i < ids.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if ((i | j) == req && !ids[i].empty() && !ids[j].empty())
            {
                cout << ids[i][0] + 1 << " " << ids[j][0] + 1 << "\n";
                return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}