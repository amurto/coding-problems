#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n;
    cin >> n;
    string a[n], b[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int j = 0; j < n; j++)
        if (a[0][j] != b[0][j])
            for (int i = 0; i < n; i++)
                a[i][j] ^= 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != b[i])
            for (int j = 0; j < n; j++)
                a[i][j] ^= 1;
        if (a[i] != b[i])
            return false;
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