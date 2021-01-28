#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n;
    cin >> n;
    for (int i = 0; 2020 * i <= n; i++)
        for (int j = 0; 2020 * i + 2021 * j <= n; j++)
            if (2020 * i + 2021 * j == n)
                return true;
    return false;
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