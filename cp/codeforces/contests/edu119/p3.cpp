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

const ll inf = 1e18 + 5;
bool is_overflow(ll x, ll y, ll n)
{
    return x > (n / y);
}

vector<ll> compress(string &str, int n)
{
    vector<ll> st;
    string tmp = "";
    for (int i = 0; i < n;)
    {
        if (str[i] == 'a')
        {
            tmp.pb('a');
            st.pb(0);
            i++;
        }
        else
        {
            int r = i;
            while (r < n && str[r] == '*')
                r++;
            tmp.pb('*');
            st.pb(r - i);
            i = r;
        }
    }
    swap(str, tmp);
    return st;
}

string solve(int tc)
{
    int n, stars = 0, id = -1;
    ll k, x;
    string str, res = "";
    cin >> n >> k >> x >> str;
    vector<ll> st = compress(str, n);
    n = (int)str.length();
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '*')
        {
            st[i] *= k;
            st[i]++;
            stars++;
        }
    }
    if (stars == 0)
        return str;
    vector<ll> suf(n + 1), cnt(n);
    suf[n] = 1;
    for (int j = n - 1; id == -1 && j >= 0; j--)
    {
        if (str[j] == '*')
        {
            if (is_overflow(suf[j + 1], st[j], x-1))
                id = j;
            else
                suf[j] = suf[j + 1] * st[j];
        }
        else
            suf[j] = suf[j + 1];
    }
    for (int i = id; x > 0 && i < n; i++)
    {
        if (str[i] == '*')
        {
            ll sum = 0, tmp = -1;
            for (int j = 0; tmp == -1 && j < st[i]; j++)
            {
                sum += suf[i + 1];
                if (sum >= x)
                    tmp = j;
            }
            x = x - sum + suf[i + 1];
            if (tmp >= 0)
                cnt[i] = tmp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'a')
            res.pb('a');
        else
            for (int t = 0; t < cnt[i]; t++)
                res.pb('b');
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
    for (int tc = 1; tc <= t; tc++)
        cout << solve(tc) << "\n";
    return 0;
}