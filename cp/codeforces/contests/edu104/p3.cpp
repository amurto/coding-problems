#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    int m = n / 2;
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (n % 2 == 0)
            {
                if (j - i == m)
                    cout << 0 << " ";
                else if (j - i > m)
                    cout << 1 << " ";
                else
                    cout << -1 << " ";
            }
            else
            {
                if (j - i <= m)
                    cout << 1 << " ";
                else
                    cout << -1 << " ";
            }
        }
    }
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