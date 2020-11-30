// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1410
// 10469 - To Carry or not to Carry

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    while (cin >> a >> b)
    {
        int res = 0;
        for (int i = 1; i <= max(a, b); i <<= 1)
        {
            if ((a & i) && (b & i))
                continue;
            if ((a & i) || (b & i))
                res |= i;
        }
        cout << res << "\n";
    }
    return 0;
}