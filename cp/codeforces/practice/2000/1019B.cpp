// https://codeforces.com/contest/1019/problem/B
// The hat

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int query(int i, int n)
{
    int v1, v2;
    cout << "? " << i << endl;
    cin >> v1;
    cout << "? " << i + n / 2 << endl;
    cin >> v2;
    if (v1 == v2)
        return 0;
    else if (v1 < v2)
        return -1;
    return 1;
}

void solve()
{
    int n;
    cin >> n;
    if (n % 4 > 0)
    {
        cout << "! -1" << endl;
        return;
    }
    int v = query(1, n);
    if (v == 0)
    {
        cout << "! " << 1 << endl;
        return;
    }
    int low = 1, high = n / 2;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int q = query(mid, n);
        if (q == 0)
        {
            cout << "! " << mid << endl;
            return;
        }
        if (v == q)
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout << "! -1" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}