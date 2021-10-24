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

int hp(int n)
{
    int bits = 0;
    while (n > 0)
    {
        n /= 2;
        bits++;
    }
    return bits;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    if (k == 0)
    {
        cout << "YES\n0\n";
        return;
    }
    int h = hp(n);
    for (int i = 1; i <= h; i++)
    {
        int cur = k;
        for (int j = i; j >= 1; j--, cur = abs(cur))
            cur -= (1 << (j - 1));
        if (cur == 0)
        {
            cout << "YES\n";
            vector<int> op;
            int l = 1, r = k;
            cur = k;
            for (int j = i; j >= 1; j--)
            {
                int m = 1 << (j - 1);
                if (cur == 0)
                {
                    op.pb(1);
                    l = 1;
                    r = m;
                }
                else
                {
                    if (r - m >= 0)
                    {
                        op.pb(r - m + 1);
                        if (op.back() < l)
                            r = l - 1, l = op.back();
                        else
                            r = op.back() - 1;
                    }
                    else
                    {
                        op.pb(l);
                        if (l + m - 1 <= r)
                            l += m;
                        else
                            l = r + 1, r = op.back() + m - 1;
                    }
                }
                cur -= m;
                cur = abs(cur);
            }
            reverse(op.begin(), op.end());
            cout << i << "\n";
            for (int j = 0; j < i; j++)
                cout << op[j] << "\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}