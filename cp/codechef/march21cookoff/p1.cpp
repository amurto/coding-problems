#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int cur = 1, x = 0;
    while (x == 0)
    {
        cout << cur * cur << "\n";
        fflush(stdout);
        cin >> x;
        cur++;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}