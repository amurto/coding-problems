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
    cin >> n;

    // 1 -> n-1, 2 -> n-2
    ll cnt =0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1 + i; j <= n; j++)
        {
            ll f = (j - i) * (j + 1), s = (j - i + 1) * j;
            if (f % i == 0 || s % i == 0)
            {
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}