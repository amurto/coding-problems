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

const int inf = 1e9 + 7;

vector<int> z_function(string s)
{
    int n = (int)s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

// str = "abcabcabc"
// here, minimum period is 3
int find_min_period(string str)
{
    int n = (int)str.length();
    str = str + str;
    vector<int> z = z_function(str);
    for (int i = 0; i < n; i++)
        if (z[i + 1] >= n)
            return i + 1;
    return n;
}

int solve()
{
    int n, res = -inf;
    string str;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> str;
    int dv = find_min_period(str);
    vector<int> min_val(dv, inf), max_val(dv);
    for (int i = 0; i < n; i++)
    {
        int t = i % dv;
        min_val[t] = min(min_val[t], arr[i]);
        max_val[t] = max(max_val[t], arr[i]);
    }
    int mn = min_val[0], mx = max_val[0];
    for (int i = 1; i < dv; i++)
    {
        res = max(res, max(max_val[i] - mn, mx - min_val[i]));
        mn = min(mn, min_val[i]);
        mx = max(mx, max_val[i]);
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