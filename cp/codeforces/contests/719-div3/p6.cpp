#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int query(int l, int r)
{
    int sum;
    cout << "? " << l << " " << r << "\n";
    fflush(stdout);
    cin >> sum;
    if (sum == -1)
        exit(0);
    return sum;
}

void solve()
{
    int n, t, k;
    cin >> n >> t >> k;
    t--;
    int low = 1, high = n, res = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mid - query(1, mid) >= k)
        {
            res = min(res, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << "! " << res << "\n";
    fflush(stdout);
}

int main()
{
    solve();
    return 0;
}