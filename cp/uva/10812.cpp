// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1753
// 10812 - Beat the Spread!

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
        int sum, diff;
        cin >> sum >> diff;
        int a = (sum + diff) / 2;
        int b = sum - a;
        if (a >= 0 && b >= 0 && max(a, b) - min(a, b) == diff)
            cout << a << " " << b << "\n";
        else
            cout << "impossible\n";
    }
    return 0;
}