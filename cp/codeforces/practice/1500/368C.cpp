// https://codeforces.com/contest/368/problem/C
// Sereja and Algorithm

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m, l, r;
    string str;
    cin >> str >> m;
    int n = str.length();
    vector<vector<int>> f(n + 1, vector<int>(3));
    for (int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1];
        f[i][str[i - 1] - 'x']++;
    }
    while (m-- > 0)
    {
        cin >> l >> r;
        if (r - l + 1 < 3)
        {
            cout << "YES\n";
            continue;
        }
        vector<int> cur = f[r];
        for (int i = 0; i < 3; i++)
            cur[i] -= f[l - 1][i];
        sort(cur.begin(), cur.end());
        cur[2] - cur[0] <= 1 ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}