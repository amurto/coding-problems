// https://codeforces.com/contest/441/problem/C
// Valera and Tubes

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
const int N = 9e4 + 1;
vector<pair<int, int>> res;
void dfs(int n, int m, int r, int c)
{
    if (r > n)
        return;
    res.pb({r, c});
    int inc = (r & 1) ? 1 : -1;
    c += inc;
    if (c < 1 || c > m)
    {
        c -= inc;
        r++;
    }
    dfs(n, m, r, c);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    dfs(n, m, 1, 1);
    int i, j, sz = res.size();
    for (i = 0, j = 1; j < k; i += 2, j++)
    {
        cout << 2 << " ";
        cout << res[i].first << " " << res[i].second << " ";
        cout << res[i + 1].first << " " << res[i + 1].second << "\n";
    }
    cout << sz - i << " ";
    while (i < res.size())
    {
        cout << res[i].first << " " << res[i].second << " ";
        i++;
    }
    return 0;
}