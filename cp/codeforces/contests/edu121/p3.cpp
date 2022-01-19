#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

ll nc2(int x)
{
    return (x * 1ll * (x + 1)) / 2;
}

ll solve()
{
    int n;
    ll res = 0;
    cin >> n;
    vector<int> k(n), h(n);
    for (int i = 0; i < n; i++)
        cin >> k[i];
    for (int i = 0; i < n; i++)
        cin >> h[i];
    vector<pii> ivs;
    for (int i = 0; i < n; i++)
        ivs.pb({k[i] - h[i] + 1, k[i]});
    sort(ivs.begin(), ivs.end());
    for (int i = 0; i < n;)
    {
        int r = ivs[i].second, itr = i;
        while (itr < n && ivs[itr].first <= r)
        {
            r = max(r, ivs[itr].second);
            itr++;
        }
        res += nc2(r - ivs[i].first + 1);
        i = itr;
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