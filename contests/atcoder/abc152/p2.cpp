#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int a, b;
    cin >> a >> b;
    if (a == b)
        while (a-- > 0)
            cout << max(a, b);
    else if (a < b)
        while (b-- > 0)
            cout << a;
    else
        while (a-- > 0)
            cout << b;
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}