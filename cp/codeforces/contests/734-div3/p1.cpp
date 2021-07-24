#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    int r1 = n / 3, r2 = n / 3;
    n %= 3;
    if (n == 1)
        r1++;
    else if (n == 2)
        r2++;
    cout << r1 << " " << r2 << "\n";
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