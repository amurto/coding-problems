#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        ll v, k, rem = 0, ans = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> v;
            rem = rem + v;
            if (ans == 0 && rem < k)
                ans = i;
            rem = max(0ll, rem - k);
        }
        if (ans == 0) {
            ans = n;
            if (rem > 0)
                ans = ans + (rem / k);
            ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}