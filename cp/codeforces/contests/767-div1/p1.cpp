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

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), itr(n + 1), sz(n + 1), res;
    vector<vector<int>> ids(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        ids[arr[i]].pb(i);
    }
    for (int i = 0; i <= n; i++)
        sz[i] = (int)ids[i].size();
    int taken = 0, mx = -1, cur_mex = -1;
    while (cur_mex != 0)
    {
        int mex = 0;
        while (mex <= n && itr[mex] < sz[mex])
        {
            mx = max(mx, ids[mex][itr[mex]]);
            mex++;
        }
        if (mex == 0)
            break;
        for (int i = 0; i < mex; i++)
        {
            while (itr[i] < sz[i] && ids[i][itr[i]] <= mx)
            {
                taken++;
                itr[i]++;
            }
        }
        cur_mex = mex;
        res.pb(mex);
    }
    for (int i = 0; i <= n; i++)
    {
        while (itr[i] < sz[i] && ids[i][itr[i]] <= mx)
        {
            taken++;
            itr[i]++;
        }
    }
    int zeroes = n - taken;
    while (zeroes > 0)
    {
        res.pb(0);
        zeroes--;
    }
    cout << (int)res.size() << "\n";
    for (int x : res)
        cout << x << " ";
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