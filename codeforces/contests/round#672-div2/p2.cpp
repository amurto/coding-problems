#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, x;
        ll M[30] = {0};
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            for (int j = 29; j >= 0; j--)
            {
                if (x >> j == 1)
                {
                    M[j]++;
                    break;
                }
            }
        }
        ll ans=0;
        for (ll v : M)
            ans = ans + v * (v - 1) / 2;
        cout << ans << endl;
    }
    return 0;
}
