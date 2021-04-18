// https://codeforces.com/contest/1238/problem/D
// AB-string

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    string str;
    cin >> n >> str;
    ll mx = (n * 1ll * (n + 1)) / 2 - n;
    for (int j = 0; j < 2; j++)
    {
        vector<vector<int>> nxt(n, vector<int>(2, n));
        vector<int> last(2, n);
        for (int i = n - 1; i >= 0; i--)
        {
            nxt[i][0] = last[0];
            nxt[i][1] = last[1];
            last[str[i] - 'A'] = i;
        }
        for (int i = 1; i < n; i++)
            if (str[i - 1] != str[i])
                mx -= nxt[i][str[i - 1] - 'A'] - i;
        reverse(str.begin(), str.end());
    }
    for (int i = 1; i < n; i++)
        mx += (str[i - 1] != str[i]);
    cout << mx << "\n";
    return 0;
}