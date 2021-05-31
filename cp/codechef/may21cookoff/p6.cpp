#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, m;
    cin >> n >> m;
    if (m == 1)
    {
        cout << "! 0\n";
        fflush(stdout);
    }
    else
    {
        cout << "! -1\n";
        fflush(stdout);
    }
    int ans;
    cin >> ans;
    if (ans == -1)
        exit(0);
}

int main()
{
    int st, t;
    cin >> st >> t;
    while (t-- > 0)
        solve();
    return 0;
}