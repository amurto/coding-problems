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

const ll B = 61;
char calc(char ch, ll k, ll t)
{
    if (t == 0)
        return ch;
    char ch1 = 'A', ch2 = 'B';
    if (ch == 'A')
        ch1 = 'B', ch2 = 'C';
    if (ch == 'B')
        ch1 = 'C', ch2 = 'A';
    if (ch == 'C')
        ch1 = 'A', ch2 = 'B';
    if (t >= B)
        return calc(ch1, k, t - 1);
    ll h = (1ll << (t - 1));
    if (k > h)
        return calc(ch2, k - h, t - 1);
    return calc(ch1, k, t - 1);
}

void solve()
{
    string str;
    int q;
    cin >> str >> q;
    for (int i = 0; i < q; i++)
    {
        ll t, k;
        cin >> t >> k;
        ll idx = 0;
        if (t < B)
        {
            ll len = (1ll << t);
            idx = (k + len - 1) / len;
            idx--;
            k -= (len * idx);
        }
        char ch = str[idx];
        if (t >= B)
        {
            ll rem = t - (B - 1);
            rem %= 3;
            int c = ((ch - 'A') + rem) % 3;
            ch = c + 'A';
            t = B - 1;
        }
        cout << calc(ch, k, t) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}