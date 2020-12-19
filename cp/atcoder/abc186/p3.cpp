#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, res = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int cur = i;
        bool p = false;
        while (cur > 0)
        {
            if (cur % 10 == 7)
                p = true;
            cur /= 10;
        }
        cur = i;
        while (cur > 0)
        {
            if (cur % 8 == 7)
                p = true;
            cur /= 8;
        }
        if (p)
            res++;
    }
    cout << n - res << "\n";
    return 0;
}