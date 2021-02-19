#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int query(int l, int r)
{
    if (l == r)
        return -1;
    int e;
    cout << "? " << l << " " << r << "\n";
    fflush(stdout);
    cin >> e;
    return e;
}

void solve()
{
    int n, l = 0, r = 0;
    cin >> n;
    int smx = query(1, n);
    if (smx == 1 || (smx < n && query(smx, n) == smx))
    {
        l = smx + 1;
        r = n;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (query(smx, mid) == smx)
                r = mid;
            else
                l = mid + 1;
        }
    }
    else
    {
        l = 1;
        r = smx - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (query(mid + 1, smx) == smx)
                l = mid + 1;
            else
                r = mid;
        }
    }
    cout << "! " << l << endl;
}

int main()
{
    solve();
    return 0;
}