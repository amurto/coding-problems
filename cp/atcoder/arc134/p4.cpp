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
    int sz = 2 * n;
    vector<int> arr(sz), seq;
    map<int, vector<int>> ids;
    for (int i = 0; i < sz; i++)
    {
        cin >> arr[i];
        if (i < n)
        {
            seq.pb(arr[i]);
            ids[arr[i]].pb(i);
        }
    }
    sort(seq.begin(), seq.end());
    seq.resize(unique(seq.begin(), seq.end()) - seq.begin());
    vector<int> res;
    int mx = arr[ids[seq[0]][0] + n], itr = -1;
    for (int i = 0; i < (int)seq.size() && seq[i] < mx; i++)
    {
        for (int id : ids[seq[i]])
        {
            if (id > itr)
            {
                res.pb(id);
                res.pb(id + n);
                itr = id;
            }
        }
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < (int)res.size(); i++)
        res[i] = arr[res[i]];
    vector<int> res2;
    mx = arr[ids[seq[0]][0] + n];
    itr = -1;
    for (int i = 0; i < (int)seq.size() && seq[i] <= mx; i++)
    {
        for (int id : ids[seq[i]])
        {
            if (id > itr)
            {
                res2.pb(id);
                res2.pb(id + n);
                itr = id;
            }
        }
    }
    sort(res2.begin(), res2.end());
    for (int i = 0; i < (int)res2.size(); i++)
        res2[i] = arr[res2[i]];
    if (res.empty() || res2 < res)
        swap(res, res2);
    for (int i : ids[seq[0]])
    {
        vector<int> tmp(2);
        tmp[0] = arr[i];
        tmp[1] = arr[i + n];
        if (res.empty() || tmp < res)
            swap(tmp, res);
    }
    for (int x : res)
        cout << x << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}