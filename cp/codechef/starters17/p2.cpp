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

ll inv_cnt(string &str)
{
    ll res = 0;
    array<ll, 2> cnt{0, 0};
    for (char ch : str)
    {
        if (ch == '0')
            res += cnt[1];
        cnt[ch - '0']++;
    }
    return res;
}

ll solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> ids(n);
    vector<string> arr(n);
    vector<vector<int>> st(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (char ch : arr[i])
            st[i][ch - '0']++;
    }
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int &i1, int &i2)
         {
        if (st[i1][1]==st[i2][1])
            return st[i1][0]>st[i2][0];
        return st[i1][1] < st[i2][1]; });
    string str = "";
    for (int i : ids)
        for (char ch : arr[i])
            str.pb(ch);
    return inv_cnt(str);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}