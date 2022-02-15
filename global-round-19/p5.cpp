#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back

ll solve()
{
    int n, m;
    cin >> n >> m;
    ll res = 0;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    set<pii> bad_st;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        bad_st.insert({x, y});
        bad_st.insert({y, x});
    }
    sort(arr.begin(), arr.end());
    vector<ll> freq;
    vector<pii> seq;
    vector<vector<int>> st(n + 1);
    for (int i = 0; i < n;)
    {
        int r = i;
        while (r < n && arr[i] == arr[r])
            r++;
        seq.pb({arr[i], r - i});
        freq.pb(r - i);
        st[r - i].pb(arr[i]);
        i = r;
    }
    for (int i = 1; i <= n; i++)
        if (!st[i].empty())
            reverse(st[i].rbegin(), st[i].rend());
    sort(freq.begin(), freq.end());
    freq.resize(unique(freq.begin(), freq.end()) - freq.begin());

    for (ll cx : freq)
    {
        for (ll x : st[cx])
        {
            for (int i = 0; i < (int)freq.size() && freq[i] <= cx; i++)
            {
                for (ll y : st[freq[i]])
                {
                    if (y != x && bad_st.find(pair<int, int>{x, y}) == bad_st.end())
                    {
                        res = max(res, (y + x) * (cx + freq[i]));
                        break;
                    }
                }
            }
        }
    }
    return res;
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