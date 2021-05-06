#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n;
    string str;
    cin >> n >> str;
    vector<bool> vis(26);
    vis[str[0] - 'A'] = true;
    for (int i = 1; i < n; i++)
    {
        if (vis[str[i] - 'A'] && str[i - 1] != str[i])
            return false;
        vis[str[i] - 'A'] = true;
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