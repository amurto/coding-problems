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
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    map<int, vector<int>> mp;
    set<int> cnt;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]].pb(i);
        cnt.insert(arr[i]);
    }
    for (int i = 0; i < q; i++)
    {
        int x, k;
        cin >> x >> k;
        if (cnt.find(x) == cnt.end())
            cout << "-1\n";
        else
        {
            int sz = (int)mp[x].size();
            if (sz < k)
                cout << "-1\n";
            else
                cout << mp[x][k - 1] + 1 << "\n";
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