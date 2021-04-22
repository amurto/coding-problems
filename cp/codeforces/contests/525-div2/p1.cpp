#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int x;
    cin >> x;
    if (x == 1)
    {
        cout << "-1\n";
        return;
    }
    cout << x << " " << x << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}