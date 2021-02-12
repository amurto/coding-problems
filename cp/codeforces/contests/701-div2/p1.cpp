#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int op(int x, int y)
{
    int m = 0;
    while (x > 0)
    {
        x /= y;
        m++;
    }
    return m;
}

int solve()
{
    int a, b, c = 0, i = 0, res = 1e9;
    cin >> a >> b;
    if (b == 1)
    {
        b++;
        c++;
    }
    while (i + op(a, b + i) <= res)
    {
        res = i + op(a, b + i);
        i++;
    }
    return res + c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}