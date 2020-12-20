#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll findMin(string &str, ll x, ll y)
{
    ll res = 0;
    vector<int> cnt(2);
    cnt[str[0] - '0']++;
    for (int i = 1; i < str.length(); i++)
    {
        ll zo = cnt[0] * x, oz = cnt[1] * y;
    }
    return res;
}

ll solve()
{
    string str;
    cin >> str;
    int n = str.length();
    ll x, y, res = 0;
    cin >> x >> y;
    if (str[0] == '?')
    {
        str[0] = '0';
        res = findMin(str, x, y);
        str[0] = '1';
        res = min(res, findMin(str, x, y));
    }
    else
    {
        res = findMin(str, x, y);
    }
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