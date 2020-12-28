#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int op(int x, int h)
{
    int m = 0;
    while (x > 1)
    {
        x = (x + h - 1) / h;
        m++;
    }
    return m;
}
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int target = n, hack = (n > 8) ? 8 : 2;
        vector<pair<int, int>> res;
        for (int i = 3; i < n; i++)
        {
            if (i == hack)
                continue;
            res.pb({i, n});
        }
        while (hack)
        {
            int m = op(target, hack);
            while (m-- > 0)
                res.pb({target, hack});
            target = hack;
            hack /= 4;
        }
        cout << res.size() << "\n";
        for (pair<int, int> p : res)
            cout << p.first << " " << p.second << "\n";
    }
    return 0;
}