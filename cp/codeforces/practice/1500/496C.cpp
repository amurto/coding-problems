// https://codeforces.com/contest/496/problem/C
// Removing Columns

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    int rem = 0;
    vector<int> color(n, 0);
    for (int j = 0; j < m; j++)
    {
        vector<int> nc(n);
        bool valid = true;
        nc[0] = color[0];
        for (int i = 1; i < n; i++)
        {
            if (color[i] == color[i - 1])
            {
                if (s[i][j] < s[i - 1][j])
                {
                    valid = false;
                    break;
                }
                if (s[i][j] == s[i - 1][j])
                    nc[i] = nc[i - 1];
                else
                    nc[i] = nc[i - 1] + 1;
            }
            else
            {
                nc[i] = nc[i - 1] + 1;
            }
        }
        if (!valid)
        {
            rem++;
            continue;
        }
        color = nc;
    }
    cout << rem << "\n";
    return 0;
}