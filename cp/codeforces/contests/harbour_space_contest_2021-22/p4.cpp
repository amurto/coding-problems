#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    string str, t;
    cin >> str >> t;
    reverse(str.begin(), str.end());
    reverse(t.begin(), t.end());
    int n = str.length(), m = t.length();
    vector<queue<int>> ids(26);
    for (int i = 0; i < n; i++)
        ids[str[i] - 'a'].push(i);
    int j = 0;
    for (int i = 0, p = 0; i < m; i++, p ^= 1)
    {
        char ch = t[i];
        while (!ids[ch - 'a'].empty() && (ids[ch - 'a'].front() % 2) != p)
            ids[ch - 'a'].pop();
        if (ids[ch - 'a'].empty())
            return false;
        j = ids[ch - 'a'].front();
        for (int k = 0; k < 26; k++)
            while (!ids[k].empty() && ids[k].front() <= j)
                ids[k].pop();
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}