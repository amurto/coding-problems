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

string solve()
{
    int n;
    string str;
    cin >> n >> str;
    vector<vector<int>> ids(26);
    for (int i = 0; i < 26; i++)
        ids[i].pb(-1);
    for (int i = 0; i < n; i++)
        ids[str[i] - 'a'].pb(i);
    int l = 0, r = n - 1;
    while (l < r)
    {
        int cur = str[l] - 'a', req = -1;
        for (int j = 0; req == -1 && j < cur; j++)
        {
            int id = upper_bound(ids[j].begin(), ids[j].end(), r) - ids[j].begin();
            id--;
            if (ids[j][id] > l && ids[j][id] <= r)
                req = ids[j][id];
        }
        if (req >= 0)
        {
            swap(str[l], str[req]);
            r = req - 1;
        }
        else
            l++;
    }
    return str;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}