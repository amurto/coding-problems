#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

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

string solve()
{
    int n, k;
    string str;
    cin >> n >> k >> str;
    str.pb(char('z' + 1));
    vector<int> z = z_function(str);
    int best = n - 1;
    for (int i = 1; i <= n; i++)
    {
        if (str[z[i]] < str[i + z[i]])
        {
            best = i;
            break;
        }
    }
    string res = "";
    for (int i = 0; i < k; i++)
        res.pb(str[i % best]);
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