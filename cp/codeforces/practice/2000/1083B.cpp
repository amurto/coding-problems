// https://codeforces.com/contest/1083/problem/B
// The Fair Nut and Strings

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    ll k, cur = 1, res = 0;
    string s, t;
    cin >> n >> k >> s >> t;
    for (int i = 0; i < n; i++)
    {
        if (cur < k)
        {
            cur <<= 1;
            if (s[i] == 'b')
                cur--;
            if (t[i] == 'a')
                cur--;
        }
        res += min(cur, k);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}