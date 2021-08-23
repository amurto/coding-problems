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

string solve()
{
    int n;
    string str, chs = "RB";
    map<char, int> mp;
    mp['R'] = 0;
    mp['B'] = 1;
    cin >> n >> str;
    vector<pii> ids;
    for (int i = 0; i < n;)
    {
        if (str[i] == '?')
        {
            int l = i;
            while (i < n && str[i] == '?')
                i++;
            ids.pb({l, i - 1});
        }
        else
            i++;
    }
    for (pii p : ids)
    {
        int l = p.first, r = p.second;
        if (l - 1 >= 0)
        {
            int cur = mp[str[l - 1]] ^ 1;
            while (l <= r)
            {
                str[l] = chs[cur];
                l++;
                cur ^= 1;
            }
        }
        else if (r + 1 < n)
        {
            int cur = mp[str[r + 1]] ^ 1;
            while (r >= l)
            {
                str[r] = chs[cur];
                r--;
                cur ^= 1;
            }
        }
        else
        {
            int cur = 0;
            while (l <= r)
            {
                str[l] = chs[cur];
                l++;
                cur ^= 1;
            }
        }
    }
    return str;
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