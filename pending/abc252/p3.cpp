#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, res = 1e9 + 7;
    cin >> n;
    vector<string> arr(n);
    vector<vector<int>> ids(10);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < 10; j++)
            ids[arr[i][j] - '0'].pb(j);
    }
    for (int i = 0; i < 10; i++)
    {
        int cur = 0;
        sort(ids[i].begin(), ids[i].end());
        for (int j = 0; j < n;)
        {
            int prev = j;
            while (j < n && ids[i][prev] == ids[i][j])
                j++;
            cur = max(cur, ids[i][prev] + (j - prev - 1) * 10);
        }
        res = min(res, cur);
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