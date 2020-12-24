// https://codeforces.com/contest/979/problem/B
// Treasure Hunt

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string winner(int idx)
{
    if (idx == 0)
        return "Kuro";
    else if (idx == 1)
        return "Shiro";
    return "Katie";
}

int beauty(string &str, int n)
{
    int res = 65, l = str.length(), b = 0;
    vector<int> f(256);
    for (char ch : str)
    {
        f[ch]++;
        if (f[ch] > f[res])
            res = ch;
    }
    if (n == 1)
    {
        if (f[res] == l)
            return l - 1;
        return f[res] + 1;
    }
    return min(f[res] + n, l);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    vector<pair<int, int>> res;
    for (int i = 0; i < 3; i++)
    {
        cin >> s;
        res.pb({beauty(s, n), i});
    }
    sort(res.rbegin(), res.rend());
    if (res[0].first == res[1].first)
        cout << "Draw\n";
    else
        cout << winner(res[0].second) << "\n";
    return 0;
}