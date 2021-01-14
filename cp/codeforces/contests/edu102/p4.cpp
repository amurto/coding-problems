#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, m, l, r, x = 0;
    string str;
    cin >> n >> m >> str;
    vector<int> pos(n + 1), mn(n + 1), mx(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (str[i - 1] == '+')
            x++;
        else
            x--;
        pos[i] = x;
        mn[i] = min(mn[i - 1], pos[i]);
        mx[i] = max(mx[i - 1], pos[i]);
    }
    while (m-- > 0)
    {
        cin >> l >> r;
    }
    for (int i = 0; i <= n; i++)
        cout << mn[i] << " ";
    cout << "\n";
    for (int i = 0; i <= n; i++)
        cout << pos[i] << " ";
    cout << "\n";
    for (int i = 0; i <= n; i++)
        cout << mx[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}