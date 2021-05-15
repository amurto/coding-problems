#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int dfs(string &str, string pin, int cur)
{
    if (cur == 4)
    {
        vector<bool> req(10);
        for (int i = 0; i < 10; i++)
            if (str[i] == 'o')
                req[i] = true;
        for (char ch : pin)
            req[ch - '0'] = false;
        return count(req.begin(), req.end(), true) == 0;
    }
    int res = 0;
    for (int i = 0; i < 10; i++)
    {
        if (str[i] != 'x')
        {
            string tmp = pin;
            tmp.pb(char(i + '0'));
            res += dfs(str, tmp, cur + 1);
        }
    }
    return res;
}

int solve()
{
    string str;
    cin >> str;
    int c = count(str.begin(), str.end(), 'o');
    if (c > 4)
        return 0;
    return dfs(str, "", 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}