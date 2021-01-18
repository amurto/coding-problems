// https://codeforces.com/contest/1206/problem/C
// Almost Equal

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> seq(2);
    if (n % 2 == 0)
    {
        cout << "NO\n";
        return;
    }
    for (int i = 1; i <= 2 * n; i++)
        seq[(i / 2) % 2].pb(i);
    cout << "YES\n";
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            cout << seq[i][j] << " ";
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}