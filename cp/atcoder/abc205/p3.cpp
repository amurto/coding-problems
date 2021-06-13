#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string ans = ">=<";

int solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int fa = abs(a), fb = abs(b);
    if (c & 1)
    {
        if (a == b)
            return 1;
        else if (a > b)
            return 0;
        return 2;
    }
    if (fa == fb)
        return 1;
    else if (fa > fb)
        return 0;
    return 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << ans[solve()] << "\n";
    return 0;
}