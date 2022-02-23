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

ll solve()
{
    ll n, res = 1;
    string str;
    cin >> n >> str;
    int sz = (int)str.size();
    ll right = 0, down = 0, r = 1, c = 1;
    for (char ch : str)
        if (ch == 'R')
            c++;
        else
            r++;
    ll r_allowed = n - r, c_allowed = n - c;
    r = 1, c = 1;
    for (int i = 0; i < sz; i++)
    {
        if (str[i] == 'R')
        {
            c++;
            right = max(right, 1ll);
        }
        else
        {
            r++;
            down = max(down, 1ll);
        }
        if (i == sz - 1)
            res += (down * min(r_allowed, n - r) + 1) * (right * min(c_allowed, n - c) + 1);
        else
        {
            if (str[i + 1] == 'R')
                res += (down * min(r_allowed, n - r) + 1);
            else
                res += (right * min(c_allowed, n - c) + 1);
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