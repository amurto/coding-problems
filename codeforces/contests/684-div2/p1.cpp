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
        int n, c0, c1, h;
        string str;
        cin >> n >> c0 >> c1 >> h >> str;
        int zero = 0, one = 0;
        for (char ch : str)
            if (ch == '0')
                zero++;
            else
                one++;
        int cost = zero * c0 + one * c1;
        for (int z = 0, o = n; z <= n && o >= 0; z++, o--)
            cost = min(cost, abs(z - zero) * h + z * c0 + o * c1);
        cout << cost << "\n";
    }
    return 0;
}