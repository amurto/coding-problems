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
        int n, x, ans = 1;
        cin >> n >> x;
        n -= 2;
        if (n > 0)
        {
            ans = ans + n / x;
            if (n % x > 0)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}