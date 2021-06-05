#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    ll res = 0;
    string str;
    cin >> str;
    int n = str.length();
    int last_match = -1, last_unmatch = -1;
    for (int i = 0, p = 0; i < n; i++, p ^= 1)
    {
        ll add = 0;
        if (str[i] == '?' || str[i] == '0')
        {
            int cur = 0, idx = -1;
            if (cur == p)
                idx = last_unmatch;
            else
                idx = last_match;
            add = max(add, 1ll * (i - idx));
        }
        if (str[i] == '?' || str[i] == '1')
        {
            int cur = 1, idx = -1;
            if (cur == p)
                idx = last_unmatch;
            else
                idx = last_match;
            add = max(add, 1ll * (i - idx));
        }
        res += add;
        if (str[i] != '?')
        {
            int cur = str[i] - '0';
            if (cur == p)
                last_match = i;
            else
                last_unmatch = i;
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