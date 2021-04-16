#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string solve()
{
    int n;
    vector<string> s(3);
    vector<int> z(3), o(3);
    string res = "";
    cin >> n;
    int sz = 2 * n;
    for (int i = 0; i < 3; i++)
    {
        cin >> s[i];
        z[i] = count(s[i].begin(), s[i].end(), '0');
        o[i] = count(s[i].begin(), s[i].end(), '1');
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (z[i] >= n && z[j] >= n)
            {
                int i1 = 0, i2 = 0, cnt = min(z[i], z[j]);
                while (cnt > 0)
                {
                    while (i1 < sz && s[i][i1] == '1')
                    {
                        res.pb(s[i][i1]);
                        i1++;
                    }
                    while (i2 < sz && s[j][i2] == '1')
                    {
                        res.pb(s[j][i2]);
                        i2++;
                    }
                    res.pb(s[i][i1++]);
                    i2++;
                    cnt--;
                }
                while (i1 < sz)
                    res.pb(s[i][i1++]);
                while (i2 < sz)
                    res.pb(s[j][i2++]);
                return res;
            }
            if (o[i] >= n && o[j] >= n)
            {
                int i1 = 0, i2 = 0, cnt = min(o[i], o[j]);
                while (cnt > 0)
                {
                    while (i1 < sz && s[i][i1] == '0')
                    {
                        res.pb(s[i][i1]);
                        i1++;
                    }
                    while (i2 < sz && s[j][i2] == '0')
                    {
                        res.pb(s[j][i2]);
                        i2++;
                    }
                    res.pb(s[i][i1++]);
                    i2++;
                    cnt--;
                }
                while (i1 < sz)
                    res.pb(s[i][i1++]);
                while (i2 < sz)
                    res.pb(s[j][i2++]);
                return res;
            }
        }
    }
    return "";
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